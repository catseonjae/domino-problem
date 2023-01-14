# domino-problem
도미노로 6*6 타일을 채울 때, 항상 타일을 가르는 선이 생긴다고 합니다. 이를 어떻게 증명할 수 있을까요? 코딩을 할 줄 알면 머리가 편합니다. 컴퓨터에게 모든 경우의 수를 계산시키면 되죠.

# 실행 방법
domino.exe 또는 main.cpp를 실행시키면 이를 계산하는 프로그램이 실행됩니다.

# 주의 사항
1. main.cpp를 실행했는데 컴파일 에러가 뜬다면 main.cpp파일과 같은 위치에 bits.h 파일을 다운로드 받고, #include <bits/stdc++.h> 부분을 #include "bits.h"로 바꿔서 다시 시도해 보세요.
2. domino.exe 다운로드 및 실행 과정에서 바이러스로 인식된다면 해당 경고를 무시하고 진행하거나 main.cpp파일을 이용해 프로그램을 실행하세요.

--원인--
1. main.cpp에선 bits/stdc++.h 파일을 인클루드하는데 이는 비표준 헤더로 비주얼 C++ 등의 컴파일러에서는 작동하지 않습니다. 
2. domino.exe 파일은 main.cpp 파일을 컴파일한 것에 불과하나 소스 코드가 일반적이지 않은 패턴이어서 바이러스로 인식됩니다.

# 부탁
버그나 반례를 발견하시면 pythonnopithon@gmail.com으로 제보 부탁드립니다. 소정의 보상이 있을 수도 있고 없을 수도 있습니다.
