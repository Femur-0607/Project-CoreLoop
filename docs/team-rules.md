# 개발 규칙

Unreal Engine C++ 중심 4인 팀 프로젝트용 개발 규칙이다.
게임 장르가 바뀌어도 유지되는 공통 규칙만 둔다.

## 1. 기본 원칙

### 필수
- 개발 기간은 팀 확정 후 정한다. 첫 주는 아이디어/기획서/에셋 탐색, 마지막 주는 폴리싱/문서 작업 중심으로 둔다.
- 핵심 재미 검증을 우선한다.
- C++에 핵심 로직을 둔다.
- Blueprint는 값 조정, 연출, UI 연결, 빠른 프로토타이핑에 사용한다.
- 팀 공유 문서는 Notion에 정리한다.
- 팀 개발 규칙은 이 문서를 기준으로 삼는다.

### 권장
- 기능 하나를 작게 만들고 바로 플레이해본다.
- 완벽한 구조보다 팀원이 이해하고 고칠 수 있는 구조를 우선한다.
- 발표와 제출 가능성을 항상 고려한다.

## 2. 폴더 구조

### 권장 루트 구조

```text
Source/                         # C++ 코드가 들어가는 폴더
  CoreLoop/                     # 프로젝트 메인 C++ 모듈 폴더 실제 이름은 프로젝트명에 맞춤
    Core/                       # 게임 전체에서 쓰는 기본 타입, 공통 정의, 로그 카테고리
    Gameplay/                   # 점수, 승패, 게임 흐름, 룰 같은 핵심 플레이 로직
    Characters/                 # 플레이어, 적, NPC 등 캐릭터 관련 C++ 클래스
    Interaction/                # 상호작용, 줍기, 버튼, 트리거, 조사 기능
    UI/                         # C++ 기반 UI 클래스, Widget 부모 클래스, UI 데이터 연결
    Data/                       # DataAsset, Struct, Enum, 설정값, 밸런스 데이터 타입
    Systems/                    # 저장/로드, 스폰, 상태 관리 등 여러 기능이 함께 쓰는 시스템
    Utils/                      # 작은 공용 헬퍼 함수. 너무 커지면 적절한 폴더로 이동
Content/                        # Unreal 에셋 폴더. Blueprint, 맵, 메시, 머티리얼, 사운드가 들어감
  Core/                         # 프로젝트 공통 Blueprint, 공통 DataAsset, 기본 에셋
  Characters/                   # 캐릭터 Blueprint, Skeletal Mesh, Animation
  Gameplay/                     # 플레이 오브젝트, 아이템, 장애물, 게임 규칙 관련 에셋
  UI/                           # Widget Blueprint, UI 이미지, 폰트
  Maps/                         # 레벨/맵 파일. 여러 명이 동시에 수정하지 않도록 담당자 지정
  Materials/                    # Material, Material Instance, Texture
  Audio/                        # 효과음, 배경음, 오디오 큐
  VFX/                          # Niagara, 파티클, 시각 효과
  Prototypes/                   # 임시 실험용 에셋. 최종 사용 전 정리 필요
  Developers/                   # 개인 작업 공간. 공용 에셋은 여기에 오래 두지 않음
docs/                           # 저장소에 함께 두는 팀 문서
  team-rules.md                 # 개발 규칙 문서
  ai-code-rules.md              # AI 코드 생성용 짧은 내부 규칙
```

### 필수
- C++ 코드는 `Source/<ProjectName>/` 아래에 둔다.
- 임시 작업은 `Content/Prototypes/` 또는 `Content/Developers/<Name>/`에 둔다.
- 공용 에셋 이동/삭제는 팀 채널에 먼저 알린다.
- 맵 파일은 동시에 여러 명이 수정하지 않는다.

### 권장
- 기능별로 C++ 폴더와 Content 폴더 이름을 맞춘다.
- 프로토타입이 끝난 에셋은 담당자가 정리해서 공용 폴더로 옮긴다.

## 3. 네이밍 규칙

### 필수
- C++ 클래스는 Unreal 접두사를 따른다.
  - `APlayerCharacter`
  - `UHealthComponent`
  - `FItemData`
  - `EGamePhase`
- 일반 변수와 함수 매개변수는 팀 규칙으로 소문자 시작 camelCase를 사용한다.
  - 예: `moveSpeed`, `currentHealth`, `deltaTime`
- bool 변수와 bool 매개변수는 `b` 접두사를 사용한다.
  - 예: `bIsDead`, `bCanMove`, `bHasKey`
- C++ 클래스 이름을 정할 때는 상속받는 부모 타입을 먼저 확인한다.
- Unreal의 C++ Class Wizard에서 부모 클래스를 고르면 접두사 규칙이 적용되므로 접두사를 중복해서 넣지 않는다.
  - 잘못된 예: 부모가 `AActor`인데 클래스 이름을 `APlayerCharacter`로 입력해서 최종 클래스가 `AAPlayerCharacter`가 되는 경우.
  - 올바른 예: 최종 클래스가 `APlayerCharacter`가 되어야 한다면, 생성 과정에서 중복 접두사가 붙지 않는지 확인한다.
- Blueprint 클래스는 `BP_` 접두사를 사용한다.
- Widget Blueprint는 `WBP_` 접두사를 사용한다.
- DataAsset은 `DA_` 접두사를 사용한다.
- Material은 `M_`, Material Instance는 `MI_`를 사용한다.
- Map은 `Map_` 접두사를 사용한다.

### 권장
- 이름은 역할이 바로 보이게 짓는다.
- `NewBlueprint`, `TestActor`, `FinalFinal` 같은 이름을 공용 폴더에 두지 않는다.

## 4. C++ 코드 규칙

### 필수
- Unreal Coding Standard를 따른다.
- 변수명은 팀 규칙을 우선해 소문자 시작 camelCase를 사용하고, bool은 `b` 접두사를 사용한다.
- 핵심 게임 규칙은 C++에 둔다.
- 필수 구조와 로직은 C++에 두고, 테스트 값과 표현 연결은 Blueprint/Editor에서 조정한다.
- 게임 규칙, 상태 전이, 반복 로직, 점수/승패 흐름, 상호작용 판정, 저장/로드, 스폰, 재사용 Component는 C++에 둔다.
- 다른 코드가 의존하는 필수 Component는 C++에서 만든다.
  - 예: Collision, MovementComponent, InteractionComponent, HealthComponent
- `UPROPERTY`와 `UFUNCTION` 노출 범위를 최소화한다.
- UObject 포인터 사용 전 유효성 검사를 한다.
- Tick은 꼭 필요할 때만 사용한다.
- 하드코딩된 에셋 경로를 피한다.
- 컴파일 경고를 새로 만들지 않는다.

### 권장
- 큰 클래스보다 역할이 분명한 작은 클래스/Component를 선호한다.
- DataAsset이나 Config로 조정 가능한 값은 코드에 박아두지 않는다.
- 함수 이름은 행동을 드러내게 쓴다. 예: `ApplyDamage`, `StartInteraction`.

## 5. Blueprint 규칙

### 필수
- Blueprint는 아래 용도에 사용한다.
  - 수치 조정.
  - 이동속도, 체력, 점프력, 감지 거리, 쿨타임, 데미지 같은 테스트 튜닝값.
  - 애니메이션/연출 연결.
  - UI 연결.
  - 에셋 참조 연결.
  - Mesh, Material, Sound, VFX, Widget, Camera Offset 같은 표현 연결.
  - 레벨/맵 배치.
  - Collision Preset, Input Mapping 같은 에디터 설정 연결.
  - 빠른 프로토타이핑.
- Mesh, VFX, Audio, Widget, 장식용 Child Actor 같은 표현용 Component는 Blueprint에서 조립할 수 있다.
- 복잡한 분기, 상태 전이, 반복 로직은 C++ 이전 후보로 표시한다.
- 공용 Blueprint 변수에는 카테고리와 툴팁을 정리한다.
- Blueprint에는 팀원이 조정해야 하는 값만 노출하고, 핵심 로직은 C++에 둔다.

### 권장
- Event Graph가 너무 커지면 C++ 또는 Function/Macro 정리를 검토한다.
- 프로토타입 Blueprint는 `Proto_` 또는 `Temp_` 표시를 붙인다.

## 6. Git / Git LFS 규칙

### 필수
- 각 작업은 브랜치에서 진행한다.
- `.uasset`, `.umap`, 대형 바이너리 파일은 Git LFS로 관리한다.
- 공용 `.uasset`, `.umap`을 수정하기 전에는 Git LFS Lock 또는 팀 채널 공유로 작업자를 먼저 정한다.
- `Saved/`, `Intermediate/`, `DerivedDataCache/`, `Binaries/`는 커밋하지 않는다.
- 같은 맵이나 큰 에셋은 담당자를 정하고 수정한다.
- 충돌이 나면 혼자 억지로 해결하지 말고 팀 채널에 공유한다.

### 권장
- 커밋 메시지 형식.

```text
feat: add interaction component
fix: prevent hud null access
docs: update team rules
chore: configure git lfs
```

- 코드 변경과 대형 에셋 변경은 커밋을 분리한다.

## 7. 작업 절차

### 필수
1. Notion 작업 보드에서 작업 카드를 만든다.
2. 작업 범위와 완료 기준을 적는다.
3. 브랜치를 만든다.
4. 필요한 파일만 수정한다.
5. Unreal 컴파일 또는 PIE 검증을 한다.
6. 작업 카드에 변경 내용과 검증 결과를 적는다.
7. 리뷰를 요청한다.

### 작업 카드 템플릿

```markdown
## 목표
- 

## 범위
- 수정할 파일/기능:
- 수정하지 않을 것:

## 완료 기준
- 

## 검증
- [ ] C++ 컴파일.
- [ ] PIE 실행.
- [ ] 대상 맵에서 기능 확인.
- [ ] UI 깨짐 없음.

## 위험
- 
```

## 8. 코드 리뷰 규칙

### 필수
- 리뷰는 버그, 충돌 위험, 책임 분리, 검증 누락을 먼저 본다.
- AI가 만든 코드도 사람이 만든 코드와 같은 기준으로 본다.
- 리뷰 요청에는 수정 파일, 테스트 방법, 남은 위험을 적는다.
- 리뷰 받은 사람은 반영 여부를 댓글로 남긴다.

### 권장
- 스타일만 지적하기보다 팀 규칙 링크를 함께 남긴다.
- 짧은 팀 프로젝트에서는 “나중에 완벽하게”보다 “지금 제출 가능한가”를 같이 본다.

## 9. AI 사용 규칙

### 필수
- AI에게 작업을 맡기기 전 관련 파일과 현재 구조를 알려준다.
- AI 결과를 그대로 신뢰하지 않는다.
- 컴파일, 에디터 실행, PIE 중 필요한 검증을 직접 한다.
- 외부 플러그인 추가, 대규모 구조 변경, 공용 부모 클래스 변경은 팀장 확인 후 진행한다.
- AI가 만든 코드의 책임 위치를 작업 카드에 적는다.

### 권장
- 한 번에 큰 시스템을 요청하지 말고 작은 단위로 요청한다.
- AI에게 “기존 스타일 유지”, “수정 범위 제한”, “검증 방법 포함”을 명시한다.

### AI 작업 요청 프롬프트 템플릿

```text
목표:
- 

현재 구조:
- 관련 파일:
- 관련 클래스/Blueprint:

제약:
- Unreal C++ 중심.
- Blueprint는 값 조정/UI/연출/프로토타입에만 사용.
- 외부 플러그인 추가 금지.
- 요청 범위 밖 리팩터링 금지.

원하는 변경:
- 

완료 기준:
- 

검증 방법:
- 

출력 형식:
- 변경 요약.
- 수정 파일 목록.
- 검증 결과.
- 남은 위험.
```

## 10. 빌드와 검증

### 필수
- C++ 변경 후 컴파일 성공.
- Gameplay 변경 후 PIE에서 최소 1회 확인.
- UI 변경 후 주요 해상도에서 깨짐 확인.
- 새 에셋이나 Blueprint는 참조 끊김이 없는지 확인.

### 권장
- 중요한 기능은 테스트 맵을 따로 둔다.
- 버그 수정은 재현 절차로 다시 확인한다.

## 11. 범위 축소 규칙

### 필수
- 남은 기간 안에 완성 가능성이 낮으면 기능을 줄인다.
- 핵심 루프와 발표 가능한 플레이 흐름을 우선한다.
- 아래 상황이면 범위 축소 회의를 연다.
  - 2일 이상 핵심 기능이 작동하지 않음.
  - 맵/에셋 충돌이 반복됨.
  - 팀원 1명에게 작업이 과도하게 몰림.
  - 발표용 빌드가 불안정함.

### 권장
- 기능을 줄일 때는 삭제보다 “최소 버전”을 먼저 정한다.
- 멋진 부가 요소보다 조작감, 피드백, 목표 전달을 우선한다.
