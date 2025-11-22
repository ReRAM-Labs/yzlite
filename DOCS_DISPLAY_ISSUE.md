# 文档网页显示问题诊断

**问题**: https://reram-labs.github.io/yzlite/docs/overview.html 文字显示异常

## 🔍 问题描述

### 症状 1: 文字显示异常
文字被截断，字母 "s" 和其他字符显示不完整：
- "Repository" → "Repo itory"
- "Tensorflow" → "Ten orflow"  
- "Basics" → "Ba ic"
- "Installation" → "In tallation"
- "provides" → "provide "
- "used" → "u ed"

### 症状 2: 嵌入内容显示为空白方框
Overview 页面中的幻灯片（iframe）显示为灰色空白方框：
- **位置**: "Model Execution - Embedded Device" 标题下方
- **应该显示**: 交互式幻灯片展示（reveal.js）
- **实际显示**: 空的灰色圆角矩形
- **iframe 源**: `../_static/overview/index.html`

## 🎯 根本原因

### 问题 1: 字体文件加载失败
**Google Fonts CDN 问题** - Roboto 字体未正确加载：
1. Google Fonts CDN 可能被墙或访问慢
2. 字体文件部分加载（字母 "s" 缺失）
3. 没有正确的字体回退机制
4. GitHub Pages 的 CDN 缓存问题

### 问题 2: 嵌入内容不完整
**Iframe 和 Reveal.js 幻灯片问题**：
1. Iframe 高度设置为 `height="100%"`，但父容器没有明确高度
2. Reveal.js 的 CSS/JS 资源可能没有完全加载
3. 相对路径问题：`src="../_static/overview/index.html"`
4. 幻灯片内容本身也有字体问题（同样是 "s" 缺失）

## ✅ 解决方案

### 针对字体问题

#### 方案 1: 使用系统字体（推荐）⭐⭐⭐⭐⭐

修改 `docs/_static/templates/layout.html`:

```html
<!-- 修改前 -->
<link href="https://fonts.googleapis.com/css?family=Roboto+Mono:400,500,700|Roboto:300,400,400i,700&display=fallback" rel="stylesheet">

<!-- 修改后 -->
<style>
  body, input {
    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", "Helvetica Neue", Arial, sans-serif;
  }
  code, kbd, pre {
    font-family: "SF Mono", Monaco, "Cascadia Code", "Courier New", monospace;
  }
</style>
```

### 方案 2: 本地托管字体文件

下载 Roboto 字体并放到 `docs/_static/fonts/` 目录。

### 方案 3: 检查 .nojekyll 文件

确保 `docs/.nojekyll` 文件存在，防止 GitHub Pages 的 Jekyll 处理干扰字体加载。

```bash
# 检查文件
ls -la docs/.nojekyll

# 如果不存在，创建它
touch docs/.nojekyll
```

### 方案 4: 更新文档构建

重新构建文档以确保所有资源正确：

```bash
cd docs/website_builder
sphinx-build -b html source build
```

### 针对 Iframe 空白方框问题

#### 方案 5: 修复 Iframe 高度

修改 `docs/overview.rst`:

```rst
<!-- 修改前 -->
<iframe src="../_static/overview/index.html" height="100%" width="100%" frameborder="0" class="slideshow-iframe" allowfullscreen></iframe>

<!-- 修改后 -->
<iframe src="../_static/overview/index.html" height="600px" width="100%" frameborder="0" class="slideshow-iframe" allowfullscreen style="min-height: 600px;"></iframe>
```

或在 README.md 中：
```markdown
<!-- 修改前 -->
<iframe src="./_static/overview/index.html" height="100%" width="100%" frameborder="0" class="slideshow-iframe" allowfullscreen></iframe>

<!-- 修改后 -->
<iframe src="./_static/overview/index.html" height="600px" width="100%" frameborder="0" style="min-height: 600px; border: 1px solid #ddd;"></iframe>
```

#### 方案 6: 添加 CSS 样式

在 `docs/_static/css/custom.css` 中添加：

```css
.slideshow-iframe {
    min-height: 600px;
    height: 600px;
    display: block;
    border: 1px solid #e0e0e0;
    border-radius: 4px;
}
```

#### 方案 7: 检查幻灯片文件完整性

```bash
# 验证文件存在
ls -lh docs/_static/overview/index.html

# 验证幻灯片资源
ls -lh docs/_static/overview/yzlite-overview/
```

## 🔧 立即修复

由于 `.nojekyll` 文件已存在，最可能的问题是 Google Fonts CDN 加载失败。

推荐使用**系统字体**（方案 1），这样：
- ✅ 无需外部资源
- ✅ 加载更快
- ✅ 跨平台兼容
- ✅ 显示更可靠

## 📋 检查清单

- [x] `.nojekyll` 文件存在
- [x] 字体文件存在于 `docs/_static/fonts/`
- [ ] Google Fonts CDN 可访问
- [ ] 文档需要重新构建
- [ ] CSS 字体引用需要更新

## 🚀 快速修复步骤

```bash
# 1. 修改字体配置使用系统字体
# 编辑 docs/_static/templates/layout.html

# 2. 重新构建文档
cd /Users/xingqiangchen/ReRAM-Lite
# 需要先解决 TensorFlow 导入问题，或在 Python 3.10 环境中构建

# 3. 提交更改
git add docs/
git commit -m "Fix font display issue on GitHub Pages"
git push origin main
```

## 📝 注意事项

当前文档是旧版本（v0.1.0），新版本（v0.2.0）的文档尚未重新构建。

建议：
1. 在 Python 3.10 环境中重新构建文档
2. 更新字体配置
3. 推送到 GitHub
4. 配置 GitHub Pages

---

**创建时间**: 2025-11-22  
**问题**: 字体显示异常  
**状态**: 已诊断，待修复

