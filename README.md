# Project CoreLoop

Unreal Engine C++ 중심 4인팀 게임 프로젝트 기본 문서 세트  
장르와 팀원이 아직 확정되지 않은 상태에서도 재사용할 수 있는 협업 규칙을 담는다.

## 문서 구조

```text
docs/
  ㄴ team-rules.md
  ㄴ ai-code-rules.md
exec-plans/
product-specs/
references/
AGENTS.md
ARCHITECTURE.md
README.md
```

## 각 파일 용도

- `docs/team-rules.md`: C++ 코드 작성, 폴더 구조, 에디터/Blueprint, Git/LFS 협업 규칙
- `docs/ai-code-rules.md`: AI 코드 생성용 짧은 내부 규칙
- `exec-plans/`: 현재 작업 계획과 진행 기록 저장 위치
- `product-specs/`: 게임 기획 의도와 핵심 루프 문서 저장 위치
- `references/`: 에이전트가 참고할 외부 자료의 로컬 사본 저장 위치
- `AGENTS.md`: 팀원이 읽을 필수 문서는 아니며, Codex/AI 작업자가 참고하는 짧은 안내 파일
- `ARCHITECTURE.md`: 실제 C++ 구조가 생기면 작성할 시스템 구조 도면
- `README.md`: 프로젝트 루트 안내와 문서 위치

## 프로젝트 기본 방향

### 필수
- Unreal Engine 사용
- C++ 중심 구현
- Blueprint는 값 조정, 연출, UI 연결, 빠른 프로토타이핑에 제한
- Git LFS로 Unreal 에셋 관리
- AI가 작성한 코드도 팀 코드 스타일, 책임 구조, 리뷰 절차를 따른다.

### 권장
- 전체 개발 기간에 맞게 핵심 재미 검증을 우선한다.
- 기능은 작게 만들고 빠르게 플레이해본다.
- 팀 운영 문서는 Notion에 모으고, 코드 작성 규칙은 저장소의 `docs/team-rules.md`에 둔다.

## 빠른 시작

1. 팀장이 Unreal 버전과 저장소 브랜치 규칙을 확정한다.
2. 모든 팀원이 `docs/team-rules.md`를 읽는다.
3. Notion 팀 홈의 작업 보드와 이슈/버그 DB를 확인한다.
4. Git LFS가 작동하는지 확인한다.
5. 첫 주에는 아이디어, 기획서, 참고 에셋 탐색을 먼저 진행한다.
6. 마지막 주에는 새 기능 개발을 중지하고 폴리싱, 문서 작업, 발표 준비에 집중한다.

## 팀장 공유 안내문

팀 프로젝트 시작 전에 이 저장소 문서를 먼저 읽어주세요.  
우리는 Unreal C++ 중심으로 개발하고, Blueprint는 값 조정과 연출, UI 연결, 빠른 프로토타입에만 제한해서 씁니다.  
AI 코드도 팀 코드와 똑같이 리뷰하고 검증합니다.  
첫 작업 전에는 Notion 팀 홈, 개발 규칙, Git LFS 확인까지 완료해 주세요.
