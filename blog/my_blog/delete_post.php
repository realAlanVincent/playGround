<?php
require 'db.php';

// Redirect if not logged in
if (!isset($_SESSION['user_id'])) {
    header("Location: login.php");
    exit();
}

$post_id = $_GET['id'];
$user_id = $_SESSION['user_id'];

// First, verify the user owns the post
$stmt = $conn->prepare("SELECT user_id FROM posts WHERE id = ?");
$stmt->bind_param("i", $post_id);
$stmt->execute();
$stmt->bind_result($author_id);
$stmt->fetch();
$stmt->close();

if ($user_id == $author_id) {
    // If the user is the author, delete the post
    $delete_stmt = $conn->prepare("DELETE FROM posts WHERE id = ?");
    $delete_stmt->bind_param("i", $post_id);
    $delete_stmt->execute();
    $delete_stmt->close();
} else {
    // If not the author, show an error (or just redirect)
    die("You are not authorized to delete this post.");
}

$conn->close();
header("Location: index.php"); // Redirect back to the homepage
exit();
?>