import subprocess
import os
import asyncio

async def myBuildArxivFiles():
    # Configuration
    myInputFile = "arxiv_paper.md"
    myOutputFolderName = "output"
    
    # Get the base name (arxiv_paper)
    myBaseName = os.path.splitext(myInputFile)[0]
    
    # Setup paths
    myCurrentDir = os.path.dirname(os.path.abspath(__file__))
    myOutputDir = os.path.join(myCurrentDir, myOutputFolderName)
    
    # Create the output directory if it isn't there
    if not os.path.exists(myOutputDir):
        os.makedirs(myOutputDir)
        print(f"Created folder: {myOutputFolderName}")

    # Define full paths for outputs
    myPdfOutput = os.path.join(myOutputDir, f"{myBaseName}.pdf")
    myTexOutput = os.path.join(myOutputDir, f"{myBaseName}.tex")

    try:
        # 1. Generate the PDF
        print(f"Generating PDF: {myPdfOutput}...")
        subprocess.run([
            "pandoc",
            myInputFile,
            "-o", myPdfOutput,
            "--pdf-engine=pdflatex"
        ], check=True)

        # 2. Generate the LaTeX file
        print(f"Generating LaTeX: {myTexOutput}...")
        subprocess.run([
            "pandoc",
            myInputFile,
            "-o", myTexOutput
        ], check=True)

        print("\nSuccess! Files are in the 'output' folder.")

    except subprocess.CalledProcessError as e:
        print(f"An error occurred during the build: {e}")

if __name__ == "__main__":
    asyncio.run(myBuildArxivFiles())
