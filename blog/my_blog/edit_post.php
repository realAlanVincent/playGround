<?php
require 'db.php';

// Redirect if not logged in
if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

// 1. Get the post ID from the URL and the current user's ID from the session
$post_id = $_GET['id'];
$user_id = $_SESSION['user_id'];

// 2. Fetch the post from the database to ensure the current user is the author
$stmt = $conn->prepare("SELECT title, content, user_id FROM posts WHERE id = ?");
$stmt->bind_param("i", $post_id);
$stmt->execute();
$stmt->bind_result($title, $content, $author_id);
$stmt->fetch();
$stmt->close(); // Close the first statement

// 3. Authorization Check: Make sure the logged-in user is the post's author
if ($user_id != $author_id) {
    die("Access Denied. You are not the author of this post.");
}

// 4. Handle the form submission to update the post
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $new_title = $_POST['title'];
    $new_content = $_POST['content'];
    
    $update_stmt = $conn->prepare("UPDATE posts SET title = ?, content = ? WHERE id = ?");
    $update_stmt->bind_param("ssi", $new_title, $new_content, $post_id);
    $update_stmt->execute();
    
    header("Location: index.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Edit Post</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h2>Edit Post</h2>
        <form method="post">
            <input type="text" name="title" value="<?php echo htmlspecialchars($title); ?>" required>
            <textarea name="content" rows="10" required><?php echo htmlspecialchars($content); ?></textarea>
            <button type="submit">Update Post</button>
        </form>
        <br>
        <a href="index.php">Cancel</a>
    </div>
</body>
</html>