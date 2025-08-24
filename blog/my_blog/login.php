<?php
require 'db.php';
$message = '';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = $_POST['username'];
    $password = $_POST['password'];

    $stmt = $conn->prepare("SELECT id, password FROM users WHERE username = ?");
    $stmt->bind_param("s", $username);
    $stmt->execute();
    // Beginner's Note: store_result() is needed to check num_rows.
    $stmt->store_result();

    if ($stmt->num_rows > 0) {
        $stmt->bind_result($id, $hashed_password);
        $stmt->fetch();

        // Verify the submitted password against the hashed password from the database
        if (password_verify($password, $hashed_password)) {
            // Passwords match. Store user info in the session.
            $_SESSION['user_id'] = $id;
            $_SESSION['username'] = $username;
            header("Location: index.php"); // Redirect to the main page
            exit();
        }
    }
    // If we reach here, either the username didn't exist or the password was wrong.
    $message = "Invalid username or password.";
    $stmt->close();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Login</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h2>Login</h2>
        <form method="post">
            <input type="text" name="username" placeholder="Username" required>
            <input type="password" name="password" placeholder="Password" required>
            <button type="submit">Login</button>
        </form>
        <p class="message"><?php echo $message; ?></p>
        <a href="register.php">Don't have an account? Register</a>
    </div>
</body>
</html>