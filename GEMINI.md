<!-- AICB:BEGIN {"version":1,"target":"GEMINI.md","generatedAt":"2026-09-02T00:34:33.925Z","hash":"sha256:1d5a551ce408706a2b6c79f04c0acf25f8e4b7f6221f26f83277391f7582d9c8"} -->
# AI Context Bridge — Handoff

Workspace: `/home/samuel/untitledctest/indyemu`

## Spec / context files (read these first)
- `CLAUDE.md` _(spec)_ — Claude Code instructions
- `AGENTS.md` _(spec)_ — Multi-agent instructions
- `README.md` _(spec)_ — Project README
- `.agent/AGENTS.md` _(spec)_ — Multi-agent instructions (.agent)
- `GEMINI.md` _(spec)_ — Gemini instructions
- `AGENT.md` _(spec)_ — Multi-agent instructions
- `.cursorrules` _(spec)_ — Cursor rules
- `.windsurfrules` _(spec)_ — Windsurf rules
- `.github/copilot-instructions.md` _(spec)_ — GitHub Copilot instructions (.github)

## Working files (current focus)
- `src/core/cpu/mips_cpu.cpp` _(auto:recent-edit)_
- `tests/cpu_64bit_test.cpp` _(auto:recent-edit)_
- `CMakeLists.txt` _(auto:recent-edit)_

## How to use this handoff
1. Read every file under "Spec / context files" before acting.
2. Continue the work described in the most recent thought.
3. Honor skill statuses: `ENABLED` use freely, `ASK` require explicit user confirmation each time, `DISABLED` must not be used.
4. When you reach a non-trivial decision, append a thought to `.aicb/state.json` (modelId + text + sourceReference if relevant).
<!-- AICB:END -->
