<?php require 'db.php'; ?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>My Simple Blog</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>My Simple Blog</h1>
            <div class="auth-links">
                <?php if (isset($_SESSION['user_id'])): ?>
                    <span>Welcome, <strong><?php echo htmlspecialchars($_SESSION['username']); ?></strong>!</span>
                    <a href="create_post.php">New Post</a>
                    <a href="logout.php">Logout</a>
                <?php else: ?>
                    <a href="login.php">Login</a>
                    <a href="register.php">Register</a>
                <?php endif; ?>
            </div>
        </div>
        
        <div class="posts-container">
            <?php
            // Beginner's Note: A JOIN combines rows from two tables. Here, we connect
            // 'posts' with 'users' using 'user_id' to get the author's username for each post.
            $sql = "SELECT posts.id, posts.title, posts.content, posts.created_at, users.username, posts.user_id 
                    FROM posts 
                    JOIN users ON posts.user_id = users.id 
                    ORDER BY posts.created_at DESC";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                while($post = $result->fetch_assoc()) {
                    // Beginner's Note: htmlspecialchars() prevents malicious code (like JavaScript)
                    // from being executed by converting special characters (<, >, etc.) into safe text.
                    echo "<div class='post'>";
                    echo "<h2>" . htmlspecialchars($post['title']) . "</h2>";
                    echo "<small>By " . htmlspecialchars($post['username']) . " on " . date('M d, Y', strtotime($post['created_at'])) . "</small>";
                    echo "<p>" . nl2br(htmlspecialchars($post['content'])) . "</p>";

                    // Show edit/delete links only if the logged-in user is the author
                    if (isset($_SESSION['user_id']) && $_SESSION['user_id'] == $post['user_id']) {
                        echo "<div class='post-actions'>";
                        echo "<a href='edit_post.php?id=" . $post['id'] . "'>Edit</a>";
                        echo "<a href='delete_post.php?id=" . $post['id'] . "' class='delete' onclick='return confirm(\"Are you sure you want to delete this post?\");'>Delete</a>";
                        echo "</div>";
                    }
                    echo "</div>";
                }
            } else {
                echo "<p>No posts yet. Why not create one?</p>";
            }
            ?>
        </div>
    </div>
</body>
</html>