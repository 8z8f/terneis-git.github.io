(function () {
    var blocks = document.querySelectorAll('pre');
    blocks.forEach(function (pre) {
        var btn = document.createElement('button');
        btn.className = 'copy-btn';
        btn.type = 'button';
        btn.textContent = 'copy';
        btn.addEventListener('click', function () {
            var code = pre.querySelector('code') || pre;
            var text = code.textContent;
            navigator.clipboard.writeText(text).then(function () {
                btn.textContent = 'copied';
                btn.classList.add('done');
                setTimeout(function () {
                    btn.textContent = 'copy';
                    btn.classList.remove('done');
                }, 1400);
            });
        });
        pre.appendChild(btn);
    });

    var sideLinks = document.querySelectorAll('.docs-side a[href^="#"]');
    if (!sideLinks.length) return;

    var observer = new IntersectionObserver(function (entries) {
        entries.forEach(function (e) {
            if (!e.isIntersecting) return;
            var id = e.target.id;
            sideLinks.forEach(function (a) {
                a.classList.toggle('active', a.getAttribute('href') === '#' + id);
            });
        });
    }, { rootMargin: '-80px 0px -70% 0px' });

    document.querySelectorAll('.docs-main h2, .docs-main h3').forEach(function (h) {
        if (h.id) observer.observe(h);
    });
})();
