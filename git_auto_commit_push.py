import subprocess
import os

def git_add_commit_push():
    try:
        # Adding all files to the staging area
        subprocess.run(['git', 'add', '.'], check=True)

        # Getting the status to find modified files
        status_output = subprocess.run(['git', 'status', '--porcelain'], capture_output=True, text=True, check=True)
        files = status_output.stdout.split('\n')

        for file in files:
            if file:
                # Extracting the file name from the git status output
                file_name = file[3:]
                commit_message = f"{file_name} - Adrion Project added"

                # Committing each file with a custom message
                subprocess.run(['git', 'commit', '-m', commit_message], check=True)

        # Pushing the changes to the remote repository
        subprocess.run(['git', 'push'], check=True)
        print("Changes pushed successfully.")

    except subprocess.CalledProcessError as e:
        print("Failed to execute git command:", e)

if __name__ == "__main__":
    git_add_commit_push()
