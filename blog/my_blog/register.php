<?php
require 'db.php';
$message = '';

// Check if the form was submitted
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    // Beginner's Note: Hashing passwords is a critical security step.
    // Never store plain-text passwords in your database.
    $password = password_hash($_POST['password'], PASSWORD_BCRYPT);

    // Prepare an SQL statement to prevent SQL injection attacks
    $stmt = $conn->prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    $stmt->bind_param("ss", $username, $password);

    if ($stmt->execute()) {
        $message = "Registration successful! You can now <a href='login.php'>login</a>.";
    } else {
        // Provide a more user-friendly error if the username is already taken
        $message = "That username is already taken. Please choose another.";
    }
    $stmt->close();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Register</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h2>Register</h2>
        <form method="post">
            <input type="text" name="username" placeholder="Username" required>
            <input type="password" name="password" placeholder="Password" required>
            <button type="submit">Register</button>
        </form>
        <p class="message"><?php echo $message; ?></p>
        <a href="login.php">Already have an account? Login</a>
    </div>
</body>
</html>