# AI Code Rules

AI-only quick rules for code generation. Human-facing source lives in `docs/team-rules.md`.

## Scope

- Unreal Engine project.
- Prefer C++ for gameplay logic.
- Use Blueprint only for tuning, presentation, UI wiring, and quick prototypes.
- Keep changes small and local.
- Do not refactor outside the request.

## C++ vs Editor/Blueprint

- Default rule: required structure and logic in C++; tuning values and presentation hookups in Blueprint/Editor.
- Write C++ for gameplay rules, state machines, repeated logic, validation, scoring, win/lose flow, interaction behavior, inventory/state, save/load, spawning, and reusable components.
- Create required components in C++ when other code depends on them, such as Collision, MovementComponent, InteractionComponent, and HealthComponent.
- Use Blueprint or Editor settings for tuning values such as move speed, health, jump strength, detection range, cooldowns, and damage numbers.
- Use Blueprint or Editor settings for Mesh, Material, Animation, VFX, SFX, UI wiring, camera offsets, level/map setup, collision preset selection, input mapping assignment, and quick prototypes.
- Presentation-only components such as Mesh, VFX, Audio, Widget, and decoration child actors can be assembled in Blueprint.
- If Blueprint logic grows into complex branching, loops, or shared behavior, mark it as a C++ migration candidate.
- Expose only the values designers need to tune; keep logic in C++.

## C++ Naming

- Classes keep Unreal prefixes by parent/type:
  - `A` for Actor-derived types.
  - `U` for UObject, Component, Widget types.
  - `F` for structs.
  - `E` for enums.
  - `I` for interfaces.
- Before creating a class, check parent type and avoid duplicate prefixes like `AAPlayerCharacter`.
- Functions use PascalCase: `ApplyDamage`, `StartInteraction`.
- Non-bool variables and parameters use lower camelCase: `moveSpeed`, `currentHealth`, `deltaTime`.
- Bool variables and parameters use `b` prefix: `bIsDead`, `bCanMove`, `bHasKey`.

## C++ Style

- Follow Unreal Coding Standard except where this file overrides naming.
- Keep `UPROPERTY` and `UFUNCTION` exposure minimal.
- Check UObject pointers before use.
- Use Tick only when needed.
- Avoid hardcoded asset paths.
- Do not introduce compile warnings.
- Add short Korean comments for non-obvious code flow, branching, formulas, and Unreal lifecycle assumptions so teammates can review AI-generated code faster.
- When writing debug-only logs, draw calls, editor/test shortcuts, or temporary validation code, wrap it with Unreal build preprocessors such as `#if UE_BUILD_DEBUG || UE_BUILD_DEVELOPMENT` and keep it out of Shipping builds.
- For larger files only, group related code by feature with `#pragma region <FeatureName>` / `#pragma endregion` when it improves readability; do not use regions for small files.

## Ask Before

- Engine version change.
- Project settings change.
- Build.cs or module dependency change.
- Shared C++ base class change.
- Shared Blueprint, Map, or Asset move/delete.
- Git LFS rule change.
- External plugin/library addition.
