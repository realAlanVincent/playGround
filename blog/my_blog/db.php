<?php
// Beginner's Note: session_start() is essential. It creates or resumes a session,
// allowing us to store user information (like their user_id) across different pages.
session_start();

// Database credentials
$db_host = 'localhost';
$db_user = 'root';
$db_pass = ''; // Use your database password if you have one
$db_name = 'blog';

// Establish a connection to the database
$conn = new mysqli($db_host, $db_user, $db_pass, $db_name);

// Check for a connection error and stop the script if it fails
if ($conn->connect_error) {
    die("Database Connection Failed: " . $conn->connect_error);
}