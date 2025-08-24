<?php
require 'db.php';

// If the user is not logged in, redirect them to the login page.
if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

// Handle the form submission
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $title = $_POST['title'];
    $content = $_POST['content'];
    $user_id = $_SESSION['user_id'];

    $stmt = $conn->prepare("INSERT INTO posts (user_id, title, content) VALUES (?, ?, ?)");
    $stmt->bind_param("iss", $user_id, $title, $content);
    $stmt->execute();
    
    // Redirect to the homepage after creating the post
    header("Location: index.php");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Create New Post</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h2>Create New Post</h2>
        <form method="post">
            <input type="text" name="title" placeholder="Post Title" required>
            <textarea name="content" rows="10" placeholder="Write your post here..." required></textarea>
            <button type="submit">Publish Post</button>
        </form>
        <br>
        <a href="index.php">Back to Home</a>
    </div>
</body>
</html>