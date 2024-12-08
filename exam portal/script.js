document.addEventListener('DOMContentLoaded', () => {
    const registerForm = document.getElementById('registerForm');
    const loginForm = document.getElementById('loginForm');

    // Registration handling
    if (registerForm) {
        registerForm.addEventListener('submit', function (e) {
            e.preventDefault(); // Prevent form submission

            // Collect form data
            const name = document.getElementById('name').value;
            const id = document.getElementById('id').value;
            const password = document.getElementById('password').value;
            const email = document.getElementById('email').value;
            const age = document.getElementById('age').value;
            const gender = document.querySelector('input[name="gender"]:checked')?.value;
            const address = document.getElementById('address').value;
            const branch = document.getElementById('branch').value;
            const skills = Array.from(document.querySelectorAll('input[name="skills"]:checked')).map(skill => skill.value);

            // Check if required fields are filled
            if (!name || !id || !password || !email || !age || !gender || !address || !branch) {
                alert('Please fill out all required fields.');
                return;
            }

            // Prepare user data
            const user = {
                name,
                id,
                password,
                email,
                age,
                gender,
                address,
                branch,
                skills
            };

            // Save user data to localStorage
            localStorage.setItem(email, JSON.stringify(user));

            // Clear form
            registerForm.reset();

            // Alert user and redirect to login page
            alert('Registration successful! Please login.');
            window.location.href = 'index.html';
        });
    }

    // Login handling
    if (loginForm) {
        loginForm.addEventListener('submit', function (e) {
            e.preventDefault(); // Prevent form submission

            const email = document.getElementById('loginEmail').value;
            const password = document.getElementById('loginPassword').value;

            // Retrieve stored user data from localStorage
            const storedUser = localStorage.getItem(email);

            if (storedUser) {
                const user = JSON.parse(storedUser);

                // Check if password matches
                if (user.password === password) {
                    alert('Login successful!');
                    window.location.href = 'portal.html'; // Redirect to portal page
                } else {
                    alert('Incorrect password. Please try again.');
                }
            } else {
                alert('No user found with this email. Please register.');
            }
        });
    }
});
