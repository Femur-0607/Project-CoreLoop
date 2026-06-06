# AGENTS.md

AI routing only. Keep token use low. Do not read every doc by default.

## Critical Safety

- Never use destructive commands that can delete or reset project files, including `rm`, `Remove-Item`, `del`, `rmdir`, `git reset --hard`, and `git clean`.
- Do not suggest destructive commands to users.
- If deletion is explicitly required, ask the user to do it manually or request a clearly scoped safe alternative.

## Read Policy

- Always inspect actual files before editing.
- Read only docs directly relevant to current request.
- Prefer targeted section reads/search over full-doc reads.
- Do not duplicate rules here; source of truth lives in linked docs.

## Routes

- General project/team rules, folders, Git/LFS, human-facing rules:
  - `docs/team-rules.md`
- AI code generation rules, C++ style, naming:
  - `docs/ai-code-rules.md`
- Code/system ownership and dependencies:
  - `ARCHITECTURE.md` if present and relevant.
- Product intent, game loop, design decisions:
  - `product-specs/` if present and relevant.
- Active implementation plan/progress:
  - `exec-plans/` if present and relevant.
- External/local references:
  - `references/` only when user mentions a specific reference or topic.
- Quality/security/reliability gates:
  - `QUALITY.md`, `SECURITY.md`, `RELIABILITY.md` only when present and relevant.

## Default Project Constraints

- Unreal Engine.
- C++-first gameplay logic.
- Before suggesting or creating Unreal C++ class names, check parent type and avoid duplicate Unreal prefixes such as `AAPlayerCharacter`.
- Blueprint limited to tuning, presentation, UI wiring, and quick prototypes.
- Small 4-person student team, 2026.06.15-2026.07.24. Avoid heavy process.
- AI-generated code must follow team ownership, style, review, and verification rules.

## Ask Before

- Engine version change.
- Project settings change.
- Build.cs/module dependency change.
- Shared C++ base class change.
- Shared Blueprint/Map/Asset move or delete.
- Git LFS rule change.
- External plugin/library addition.

## Final Response Shape

```text
변경:
- ...

검증:
- ...

남은 위험:
- ...
```
