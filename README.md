This is to track changes in between videos where code changes are made. I am not only providing this for myself but for others if they are having issues.<br/>
<br/>
All differences will be noted in this README for each commit.<br/>
<br/>
Video Reference:
#6 --> Logging | Game Engine Series - URL: https://www.youtube.com/watch?v=dZr-53LAlOw&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=6<br/>

IDE: Visual Studio 2022 Community Edition (Free)<br/>
<br/>
Issues: 
<br/><br/>
- Video #7 - Moved the postprocess command from Hazel to Sandbox because it was failing to copy the .dll.  It also is better practice for the dependent to know about the dependency and not vice-versa.<br/>
- Video #6 - I had added Hazel/vendor/ to the .gitignore file which caused issues with version controls. This has been removed for Video #7.<br/>
<br/>
Differences:
<br/><br/>
- Video #7 - Went ahead and added stuff to .gitignore to not include Visual Studio files in the commits. <br/>
- Video #7 - In premake5.lua for "cppdialect used "C++20" instead. This is optional but can give more language features. <br/>
- Video #7 - Premake - Version 5.0-beta2 is used instead. You have to go to https://premake.github.io/download to get the executables now. <br/>
- Video #6 - spdLog v1.x - July 23, 2024 used. No differences found yet. <br/>