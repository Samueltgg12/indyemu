<!-- AICB:BEGIN {"version":1,"target":"GEMINI.md","generatedAt":"2026-09-02T02:42:57.982Z","hash":"sha256:374d5675edb916d388a62a529ba05a1a7de925cdbd4cf8889d4e38803cb28058"} -->
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
- `src/core/memory.hpp` _(auto:recent-edit)_
- `src/core/memory.cpp` _(auto:recent-edit)_
- `src/core/cpu/mips_cpu.cpp` _(auto:recent-edit)_

## How to use this handoff
1. Read every file under "Spec / context files" before acting.
2. Continue the work described in the most recent thought.
3. Honor skill statuses: `ENABLED` use freely, `ASK` require explicit user confirmation each time, `DISABLED` must not be used.
4. When you reach a non-trivial decision, append a thought to `.aicb/state.json` (modelId + text + sourceReference if relevant).
<!-- AICB:END -->
