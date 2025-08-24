## **📝 Minimalistic PHP Blog: Project Specifications**

Document Version: 1.0  
Last Updated: August 24, 2025

### **1\. Project Overview**

This document outlines the technical specifications for a simple, beginner-friendly blog platform built with PHP and MySQL. The project is a lightweight, single-user blog application designed to provide basic user authentication and full CRUD (Create, Read, Update, Delete) functionality for blog posts. The primary goal is to offer a minimalistic and educational codebase for developers new to PHP and MySQL.

### **2\. Core Features**

* **User Authentication**:  
  * User registration with a unique username and a securely hashed password.  
  * User login and logout functionality using PHP sessions.  
* **Post Management**:  
  * Authenticated users can create new blog posts with a title and content.  
  * All posts are publicly visible on the main page.  
  * Users can only edit or delete the posts they have authored.  
  * Posts are displayed in reverse chronological order.

### **3\. Technology Stack**

* **Backend**: PHP (version 7.4 or higher recommended)  
* **Database**: MySQL or MariaDB  
* **Web Server**: Apache (typically bundled with XAMPP, WAMP, or MAMP)  
* **Frontend**: Basic HTML5 and CSS3 for structure and styling.

### **4\. Database Schema**

The application uses a MySQL database named blog with two tables: users and posts.

#### **Table: users**

Stores user credentials.

| Column | Type | Attributes | Description |
| :---- | :---- | :---- | :---- |
| id | INT | PRIMARY KEY, AUTO\_INCREMENT | Unique identifier for each user. |
| username | VARCHAR(50) | NOT NULL, UNIQUE | The user's chosen username. |
| password | VARCHAR(255) | NOT NULL | The user's securely hashed password. |

**SQL Definition:**

CREATE TABLE \`users\` (  
  \`id\` INT AUTO\_INCREMENT PRIMARY KEY,  
  \`username\` VARCHAR(50) NOT NULL UNIQUE,  
  \`password\` VARCHAR(255) NOT NULL  
);

#### **Table: posts**

Stores blog post content.

| Column | Type | Attributes | Description |
| :---- | :---- | :---- | :---- |
| id | INT | PRIMARY KEY, AUTO\_INCREMENT | Unique identifier for each post. |
| user\_id | INT | NOT NULL, FOREIGN KEY | References users.id. Links the post to its author. |
| title | VARCHAR(255) | NOT NULL | The title of the blog post. |
| content | TEXT | NOT NULL | The main body content of the blog post. |
| created\_at | TIMESTAMP | DEFAULT CURRENT\_TIMESTAMP | The date and time the post was created. |

**SQL Definition:**

CREATE TABLE \`posts\` (  
  \`id\` INT AUTO\_INCREMENT PRIMARY KEY,  
  \`user\_id\` INT NOT NULL,  
  \`title\` VARCHAR(255) NOT NULL,  
  \`content\` TEXT NOT NULL,  
  \`created\_at\` TIMESTAMP DEFAULT CURRENT\_TIMESTAMP,  
  FOREIGN KEY (\`user\_id\`) REFERENCES \`users\`(\`id\`) ON DELETE CASCADE  
);

### **5\. Project File Structure**

The project is organized into a single root directory for simplicity.

my\_blog/  
├── db.php  
├── index.php  
├── login.php  
├── register.php  
├── logout.php  
├── create\_post.php  
├── edit\_post.php  
├── delete\_post.php  
└── style.css

### **6\. Functional Breakdown of Files**

* **db.php**:  
  * **Purpose**: Handles the database connection and session management.  
  * **Logic**: Starts a PHP session with session\_start(). Connects to the MySQL database using mysqli. This file is included at the beginning of all other PHP files that require database access or session information.  
* **register.php**:  
  * **Purpose**: Handles new user registration.  
  * **Logic**: Displays a registration form (username, password). Upon submission, it hashes the password using password\_hash() with the PASSWORD\_BCRYPT algorithm and inserts the new user record into the users table.  
* **login.php**:  
  * **Purpose**: Authenticates existing users.  
  * **Logic**: Displays a login form. Upon submission, it retrieves the user record from the database based on the username. It then verifies the submitted password against the stored hash using password\_verify(). If successful, it stores the user\_id and username in the $\_SESSION superglobal and redirects to index.php.  
* **logout.php**:  
  * **Purpose**: Ends a user's session.  
  * **Logic**: Destroys the current session data using session\_destroy() and redirects the user to index.php.  
* **index.php**:  
  * **Purpose**: The main homepage. It displays all blog posts.  
  * **Logic**: Fetches all posts from the posts table, joining with the users table to display the author's username. It displays posts in descending order of creation. If a user is logged in, it shows their username and links to create a post and log out. It also displays "Edit" and "Delete" links on posts belonging to the logged-in user.  
* **create\_post.php**:  
  * **Purpose**: Provides a form to create a new blog post.  
  * **Logic**: This page is protected; it redirects to login.php if no user is logged in. It displays a form for a title and content. On submission, it inserts a new record into the posts table, linking it to the logged-in user's ID from the session.  
* **edit\_post.php**:  
  * **Purpose**: Provides a form to edit an existing post.  
  * **Logic**: This page is also protected. It retrieves the post ID from the URL query string (?id=X). It fetches the post data and verifies that the logged-in user is the author. If authorized, it displays a form pre-filled with the post's current title and content. On submission, it updates the corresponding record in the posts table.  
* **delete\_post.php**:  
  * **Purpose**: A script to delete a post.  
  * **Logic**: A protected script that takes a post ID from the URL. It verifies the logged-in user is the author before executing a DELETE SQL statement on the posts table. It then redirects back to index.php.  
* **style.css**:  
  * **Purpose**: Provides simple, clean styling for all pages.  
  * **Logic**: Uses basic CSS selectors to style the layout, forms, posts, and links for a readable and user-friendly interface.

### **7\. Setup and Installation Guide**

1. **Environment**: Set up a local server environment (XAMPP, WAMP, etc.) with Apache, MySQL, and PHP.  
2. **Database**: Use a tool like phpMyAdmin to create a new database named blog.  
3. **Tables**: Execute the SQL statements from the **Database Schema** section to create the users and posts tables.  
4. **Files**: Place all the project files into a folder (e.g., my\_blog) inside the web server's root directory (e.g., htdocs for XAMPP).  
5. **Configuration**: Open db.php and ensure the database credentials ($db\_host, $db\_user, $db\_pass, $db\_name) match your local setup.  
6. **Run**: Access the project in your web browser by navigating to http://localhost/my_blog.
