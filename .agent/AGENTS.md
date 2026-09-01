<!-- AICB:BEGIN {"version":1,"target":".agent/AGENTS.md","generatedAt":"2026-09-01T16:17:42.084Z","hash":"sha256:afac093504bba54505eede325194157209dd96ab4b929c1a0dcda38dbac0ed98"} -->
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
- `.context/_config.json` _(auto:recent-edit)_
- `.vscode/settings.json` _(auto:recent-edit)_
- `src/system/gio64_bus.cpp` _(auto:recent-edit)_
- `src/core/framebuffer.cpp` _(auto:recent-edit)_
- `src/system/bt445_ramdac.cpp` _(auto:recent-edit)_
- `src/system/bt445_ramdac.hpp` _(auto:recent-edit)_
- `hardware-docs/DQ8003_SeeqTechnology-scanned.md` _(auto:recent-edit)_
- `hardware-docs/am33c93a-scanned.md` _(auto:recent-edit)_
- `src/system/rex3.hpp` _(auto:recent-edit)_

## How to use this handoff
1. Read every file under "Spec / context files" before acting.
2. Continue the work described in the most recent thought.
3. Honor skill statuses: `ENABLED` use freely, `ASK` require explicit user confirmation each time, `DISABLED` must not be used.
4. When you reach a non-trivial decision, append a thought to `.aicb/state.json` (modelId + text + sourceReference if relevant).
<!-- AICB:END -->
