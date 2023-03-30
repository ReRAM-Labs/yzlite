!(function (r, i) {
    'function' == typeof define && define.amd
        ? define(i)
        : 'object' == typeof exports
        ? (module.exports = i())
        : i()(r.lunr)
})(this, function () {
    return function (r) {
        if (void 0 === r) throw new Error('Lunr is not present. Please include / require Lunr before this script.')
        if (void 0 === r.stemmerSupport)
            throw new Error(
                'Lunr stemmer support is not present. Please include / require Lunr stemmer support before this script.'
            )
        var mr, dr, i
        ;(r.tr = function () {
            this.pipeline.reset(),
                this.pipeline.add(r.tr.trimmer, r.tr.stopWordFilter, r.tr.stemmer),
                this.searchPipeline && (this.searchPipeline.reset(), this.searchPipeline.add(r.tr.stemmer))
        }),
            (r.tr.wordCharacters =
                'A-Za-zªºÀ-ÖØ-öø-ʸˠ-ˤᴀ-ᴥᴬ-ᵜᵢ-ᵥᵫ-ᵷᵹ-ᶾḀ-ỿⁱⁿₐ-ₜKÅℲⅎⅠ-ↈⱠ-ⱿꜢ-ꞇꞋ-ꞭꞰ-ꞷꟷ-ꟿꬰ-ꭚꭜ-ꭤﬀ-ﬆＡ-Ｚａ-ｚ'),
            (r.tr.trimmer = r.trimmerSupport.generateTrimmer(r.tr.wordCharacters)),
            r.Pipeline.registerFunction(r.tr.trimmer, 'trimmer-tr'),
            (r.tr.stemmer =
                ((mr = r.stemmerSupport.Among),
                (dr = r.stemmerSupport.SnowballProgram),
                (i = new (function () {
                    var t,
                        r = [
                            new mr('m', -1, -1),
                            new mr('n', -1, -1),
                            new mr('miz', -1, -1),
                            new mr('niz', -1, -1),
                            new mr('muz', -1, -1),
                            new mr('nuz', -1, -1),
                            new mr('müz', -1, -1),
                            new mr('nüz', -1, -1),
                            new mr('mız', -1, -1),
                            new mr('nız', -1, -1)
                        ],
                        i = [new mr('leri', -1, -1), new mr('ları', -1, -1)],
                        e = [new mr('ni', -1, -1), new mr('nu', -1, -1), new mr('nü', -1, -1), new mr('nı', -1, -1)],
                        n = [new mr('in', -1, -1), new mr('un', -1, -1), new mr('ün', -1, -1), new mr('ın', -1, -1)],
                        u = [new mr('a', -1, -1), new mr('e', -1, -1)],
                        o = [new mr('na', -1, -1), new mr('ne', -1, -1)],
                        s = [new mr('da', -1, -1), new mr('ta', -1, -1), new mr('de', -1, -1), new mr('te', -1, -1)],
                        c = [new mr('nda', -1, -1), new mr('nde', -1, -1)],
                        l = [
                            new mr('dan', -1, -1),
                            new mr('tan', -1, -1),
                            new mr('den', -1, -1),
                            new mr('ten', -1, -1)
                        ],
                        a = [new mr('ndan', -1, -1), new mr('nden', -1, -1)],
                        m = [new mr('la', -1, -1), new mr('le', -1, -1)],
                        d = [new mr('ca', -1, -1), new mr('ce', -1, -1)],
                        f = [new mr('im', -1, -1), new mr('um', -1, -1), new mr('üm', -1, -1), new mr('ım', -1, -1)],
                        b = [
                            new mr('sin', -1, -1),
                            new mr('sun', -1, -1),
                            new mr('sün', -1, -1),
                            new mr('sın', -1, -1)
                        ],
                        w = [new mr('iz', -1, -1), new mr('uz', -1, -1), new mr('üz', -1, -1), new mr('ız', -1, -1)],
                        _ = [
                            new mr('siniz', -1, -1),
                            new mr('sunuz', -1, -1),
                            new mr('sünüz', -1, -1),
                            new mr('sınız', -1, -1)
                        ],
                        k = [new mr('lar', -1, -1), new mr('ler', -1, -1)],
                        p = [
                            new mr('niz', -1, -1),
                            new mr('nuz', -1, -1),
                            new mr('nüz', -1, -1),
                            new mr('nız', -1, -1)
                        ],
                        g = [
                            new mr('dir', -1, -1),
                            new mr('tir', -1, -1),
                            new mr('dur', -1, -1),
                            new mr('tur', -1, -1),
                            new mr('dür', -1, -1),
                            new mr('tür', -1, -1),
                            new mr('dır', -1, -1),
                            new mr('tır', -1, -1)
                        ],
                        y = [new mr('casına', -1, -1), new mr('cesine', -1, -1)],
                        z = [
                            new mr('di', -1, -1),
                            new mr('ti', -1, -1),
                            new mr('dik', -1, -1),
                            new mr('tik', -1, -1),
                            new mr('duk', -1, -1),
                            new mr('tuk', -1, -1),
                            new mr('dük', -1, -1),
                            new mr('tük', -1, -1),
                            new mr('dık', -1, -1),
                            new mr('tık', -1, -1),
                            new mr('dim', -1, -1),
                            new mr('tim', -1, -1),
                            new mr('dum', -1, -1),
                            new mr('tum', -1, -1),
                            new mr('düm', -1, -1),
                            new mr('tüm', -1, -1),
                            new mr('dım', -1, -1),
                            new mr('tım', -1, -1),
                            new mr('din', -1, -1),
                            new mr('tin', -1, -1),
                            new mr('dun', -1, -1),
                            new mr('tun', -1, -1),
                            new mr('dün', -1, -1),
                            new mr('tün', -1, -1),
                            new mr('dın', -1, -1),
                            new mr('tın', -1, -1),
                            new mr('du', -1, -1),
                            new mr('tu', -1, -1),
                            new mr('dü', -1, -1),
                            new mr('tü', -1, -1),
                            new mr('dı', -1, -1),
                            new mr('tı', -1, -1)
                        ],
                        h = [
                            new mr('sa', -1, -1),
                            new mr('se', -1, -1),
                            new mr('sak', -1, -1),
                            new mr('sek', -1, -1),
                            new mr('sam', -1, -1),
                            new mr('sem', -1, -1),
                            new mr('san', -1, -1),
                            new mr('sen', -1, -1)
                        ],
                        v = [
                            new mr('miş', -1, -1),
                            new mr('muş', -1, -1),
                            new mr('müş', -1, -1),
                            new mr('mış', -1, -1)
                        ],
                        q = [new mr('b', -1, 1), new mr('c', -1, 2), new mr('d', -1, 3), new mr('ğ', -1, 4)],
                        C = [17, 65, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 8, 0, 0, 0, 0, 0, 0, 1],
                        P = [1, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1],
                        F = [65],
                        S = [65],
                        W = [
                            [
                                'a',
                                [1, 64, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
                                97,
                                305
                            ],
                            ['e', [17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130], 101, 252],
                            [
                                'ı',
                                [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
                                97,
                                305
                            ],
                            ['i', [17], 101, 105],
                            ['o', F, 111, 117],
                            ['ö', S, 246, 252],
                            ['u', F, 111, 117]
                        ],
                        L = new dr()
                    function x(r, i, e) {
                        for (;;) {
                            var n = L.limit - L.cursor
                            if (L.in_grouping_b(r, i, e)) {
                                L.cursor = L.limit - n
                                break
                            }
                            if (((L.cursor = L.limit - n), L.cursor <= L.limit_backward)) return !1
                            L.cursor--
                        }
                        return !0
                    }
                    function A() {
                        var r, i
                        ;(r = L.limit - L.cursor), x(C, 97, 305)
                        for (var e = 0; e < W.length; e++) {
                            i = L.limit - L.cursor
                            var n = W[e]
                            if (L.eq_s_b(1, n[0]) && x(n[1], n[2], n[3])) return (L.cursor = L.limit - r), !0
                            L.cursor = L.limit - i
                        }
                        return (
                            (L.cursor = L.limit - i),
                            !(!L.eq_s_b(1, 'ü') || !x(S, 246, 252)) && ((L.cursor = L.limit - r), !0)
                        )
                    }
                    function E(r, i) {
                        var e,
                            n = L.limit - L.cursor
                        return r() &&
                            ((L.cursor = L.limit - n),
                            L.cursor > L.limit_backward && (L.cursor--, (e = L.limit - L.cursor), i()))
                            ? ((L.cursor = L.limit - e), !0)
                            : ((L.cursor = L.limit - n),
                              r()
                                  ? ((L.cursor = L.limit - n), !1)
                                  : ((L.cursor = L.limit - n),
                                    !(L.cursor <= L.limit_backward) &&
                                        (L.cursor--, !!i() && ((L.cursor = L.limit - n), !0))))
                    }
                    function j(r) {
                        return E(r, function () {
                            return L.in_grouping_b(C, 97, 305)
                        })
                    }
                    function T() {
                        return j(function () {
                            return L.eq_s_b(1, 'n')
                        })
                    }
                    function Z() {
                        return j(function () {
                            return L.eq_s_b(1, 'y')
                        })
                    }
                    function B() {
                        return (
                            L.find_among_b(r, 10) &&
                            E(
                                function () {
                                    return L.in_grouping_b(P, 105, 305)
                                },
                                function () {
                                    return L.out_grouping_b(C, 97, 305)
                                }
                            )
                        )
                    }
                    function D() {
                        return (
                            A() &&
                            L.in_grouping_b(P, 105, 305) &&
                            j(function () {
                                return L.eq_s_b(1, 's')
                            })
                        )
                    }
                    function G() {
                        return L.find_among_b(i, 2)
                    }
                    function H() {
                        return A() && L.find_among_b(n, 4) && T()
                    }
                    function I() {
                        return A() && L.find_among_b(s, 4)
                    }
                    function J() {
                        return A() && L.find_among_b(c, 2)
                    }
                    function K() {
                        return A() && L.find_among_b(f, 4) && Z()
                    }
                    function M() {
                        return A() && L.find_among_b(b, 4)
                    }
                    function N() {
                        return A() && L.find_among_b(w, 4) && Z()
                    }
                    function O() {
                        return L.find_among_b(_, 4)
                    }
                    function Q() {
                        return A() && L.find_among_b(k, 2)
                    }
                    function R() {
                        return A() && L.find_among_b(g, 8)
                    }
                    function U() {
                        return A() && L.find_among_b(z, 32) && Z()
                    }
                    function V() {
                        return L.find_among_b(h, 8) && Z()
                    }
                    function X() {
                        return A() && L.find_among_b(v, 4) && Z()
                    }
                    function Y() {
                        var r = L.limit - L.cursor
                        return !(
                            X() ||
                            ((L.cursor = L.limit - r),
                            U() ||
                                ((L.cursor = L.limit - r),
                                V() || ((L.cursor = L.limit - r), L.eq_s_b(3, 'ken') && Z())))
                        )
                    }
                    function $() {
                        if (L.find_among_b(y, 2)) {
                            var r = L.limit - L.cursor
                            if (
                                (O() ||
                                    ((L.cursor = L.limit - r),
                                    Q() ||
                                        ((L.cursor = L.limit - r),
                                        K() ||
                                            ((L.cursor = L.limit - r),
                                            M() || ((L.cursor = L.limit - r), N() || (L.cursor = L.limit - r))))),
                                X())
                            )
                                return !1
                        }
                        return !0
                    }
                    function rr() {
                        if (!A() || !L.find_among_b(p, 4)) return !0
                        var r = L.limit - L.cursor
                        return !U() && ((L.cursor = L.limit - r), !V())
                    }
                    function ir() {
                        var r,
                            i,
                            e,
                            n = L.limit - L.cursor
                        if (
                            ((L.ket = L.cursor),
                            (t = !0),
                            Y() &&
                                ((L.cursor = L.limit - n),
                                $() &&
                                    ((L.cursor = L.limit - n),
                                    (function () {
                                        if (Q()) {
                                            ;(L.bra = L.cursor), L.slice_del()
                                            var r = L.limit - L.cursor
                                            return (
                                                (L.ket = L.cursor),
                                                R() ||
                                                    ((L.cursor = L.limit - r),
                                                    U() ||
                                                        ((L.cursor = L.limit - r),
                                                        V() ||
                                                            ((L.cursor = L.limit - r),
                                                            X() || (L.cursor = L.limit - r)))),
                                                (t = !1)
                                            )
                                        }
                                        return !0
                                    })() &&
                                        ((L.cursor = L.limit - n),
                                        rr() &&
                                            ((L.cursor = L.limit - n),
                                            (e = L.limit - L.cursor),
                                            !(
                                                O() ||
                                                ((L.cursor = L.limit - e),
                                                N() ||
                                                    ((L.cursor = L.limit - e), M() || ((L.cursor = L.limit - e), K())))
                                            ) ||
                                                ((L.bra = L.cursor),
                                                L.slice_del(),
                                                (i = L.limit - L.cursor),
                                                (L.ket = L.cursor),
                                                X() || (L.cursor = L.limit - i),
                                                0))))))
                        ) {
                            if (((L.cursor = L.limit - n), !R())) return
                            ;(L.bra = L.cursor),
                                L.slice_del(),
                                (L.ket = L.cursor),
                                (r = L.limit - L.cursor),
                                O() ||
                                    ((L.cursor = L.limit - r),
                                    Q() ||
                                        ((L.cursor = L.limit - r),
                                        K() ||
                                            ((L.cursor = L.limit - r),
                                            M() || ((L.cursor = L.limit - r), N() || (L.cursor = L.limit - r))))),
                                X() || (L.cursor = L.limit - r)
                        }
                        ;(L.bra = L.cursor), L.slice_del()
                    }
                    function er() {
                        var r, i, e, n
                        if (((L.ket = L.cursor), L.eq_s_b(2, 'ki'))) {
                            if (((r = L.limit - L.cursor), I()))
                                return (
                                    (L.bra = L.cursor),
                                    L.slice_del(),
                                    (i = L.limit - L.cursor),
                                    (L.ket = L.cursor),
                                    Q()
                                        ? ((L.bra = L.cursor), L.slice_del(), er())
                                        : ((L.cursor = L.limit - i),
                                          B() &&
                                              ((L.bra = L.cursor),
                                              L.slice_del(),
                                              (L.ket = L.cursor),
                                              Q() && ((L.bra = L.cursor), L.slice_del(), er()))),
                                    !0
                                )
                            if (((L.cursor = L.limit - r), H())) {
                                if (
                                    ((L.bra = L.cursor),
                                    L.slice_del(),
                                    (L.ket = L.cursor),
                                    (e = L.limit - L.cursor),
                                    G())
                                )
                                    (L.bra = L.cursor), L.slice_del()
                                else {
                                    if (
                                        ((L.cursor = L.limit - e),
                                        (L.ket = L.cursor),
                                        !B() && ((L.cursor = L.limit - e), !D() && ((L.cursor = L.limit - e), !er())))
                                    )
                                        return !0
                                    ;(L.bra = L.cursor),
                                        L.slice_del(),
                                        (L.ket = L.cursor),
                                        Q() && ((L.bra = L.cursor), L.slice_del(), er())
                                }
                                return !0
                            }
                            if (((L.cursor = L.limit - r), J())) {
                                if (((n = L.limit - L.cursor), G())) (L.bra = L.cursor), L.slice_del()
                                else if (((L.cursor = L.limit - n), D()))
                                    (L.bra = L.cursor),
                                        L.slice_del(),
                                        (L.ket = L.cursor),
                                        Q() && ((L.bra = L.cursor), L.slice_del(), er())
                                else if (((L.cursor = L.limit - n), !er())) return !1
                                return !0
                            }
                        }
                        return !1
                    }
                    function nr(r) {
                        if (((L.ket = L.cursor), !J() && ((L.cursor = L.limit - r), !A() || !L.find_among_b(o, 2))))
                            return !1
                        var i = L.limit - L.cursor
                        if (G()) (L.bra = L.cursor), L.slice_del()
                        else if (((L.cursor = L.limit - i), D()))
                            (L.bra = L.cursor),
                                L.slice_del(),
                                (L.ket = L.cursor),
                                Q() && ((L.bra = L.cursor), L.slice_del(), er())
                        else if (((L.cursor = L.limit - i), !er())) return !1
                        return !0
                    }
                    function tr(r) {
                        if (
                            ((L.ket = L.cursor),
                            !((A() && L.find_among_b(a, 2)) || ((L.cursor = L.limit - r), A() && L.find_among_b(e, 4))))
                        )
                            return !1
                        var i = L.limit - L.cursor
                        return (
                            !(!D() && ((L.cursor = L.limit - i), !G())) &&
                            ((L.bra = L.cursor),
                            L.slice_del(),
                            (L.ket = L.cursor),
                            Q() && ((L.bra = L.cursor), L.slice_del(), er()),
                            !0)
                        )
                    }
                    function ur() {
                        var r,
                            i = L.limit - L.cursor
                        return (
                            (L.ket = L.cursor),
                            !!(H() || ((L.cursor = L.limit - i), A() && L.find_among_b(m, 2) && Z())) &&
                                ((L.bra = L.cursor),
                                L.slice_del(),
                                (r = L.limit - L.cursor),
                                (L.ket = L.cursor),
                                !(!Q() || ((L.bra = L.cursor), L.slice_del(), !er())) ||
                                    ((L.cursor = L.limit - r),
                                    (L.ket = L.cursor),
                                    (B() || ((L.cursor = L.limit - r), D() || ((L.cursor = L.limit - r), er()))) &&
                                        ((L.bra = L.cursor),
                                        L.slice_del(),
                                        (L.ket = L.cursor),
                                        Q() && ((L.bra = L.cursor), L.slice_del(), er())),
                                    !0))
                        )
                    }
                    function or() {
                        var r,
                            i,
                            e = L.limit - L.cursor
                        if (
                            ((L.ket = L.cursor),
                            !(
                                I() ||
                                ((L.cursor = L.limit - e),
                                (A() && L.in_grouping_b(P, 105, 305) && Z()) ||
                                    ((L.cursor = L.limit - e), A() && L.find_among_b(u, 2) && Z()))
                            ))
                        )
                            return !1
                        if (((L.bra = L.cursor), L.slice_del(), (L.ket = L.cursor), (r = L.limit - L.cursor), B()))
                            (L.bra = L.cursor),
                                L.slice_del(),
                                (i = L.limit - L.cursor),
                                (L.ket = L.cursor),
                                Q() || (L.cursor = L.limit - i)
                        else if (((L.cursor = L.limit - r), !Q())) return !0
                        return (L.bra = L.cursor), L.slice_del(), (L.ket = L.cursor), er(), !0
                    }
                    function sr() {
                        var r,
                            i,
                            e = L.limit - L.cursor
                        if (((L.ket = L.cursor), Q())) return (L.bra = L.cursor), L.slice_del(), void er()
                        if (((L.cursor = L.limit - e), (L.ket = L.cursor), A() && L.find_among_b(d, 2) && T()))
                            if (((L.bra = L.cursor), L.slice_del(), (r = L.limit - L.cursor), (L.ket = L.cursor), G()))
                                (L.bra = L.cursor), L.slice_del()
                            else {
                                if (
                                    ((L.cursor = L.limit - r),
                                    (L.ket = L.cursor),
                                    !B() && ((L.cursor = L.limit - r), !D()))
                                ) {
                                    if (((L.cursor = L.limit - r), (L.ket = L.cursor), !Q())) return
                                    if (((L.bra = L.cursor), L.slice_del(), !er())) return
                                }
                                ;(L.bra = L.cursor),
                                    L.slice_del(),
                                    (L.ket = L.cursor),
                                    Q() && ((L.bra = L.cursor), L.slice_del(), er())
                            }
                        else if (((L.cursor = L.limit - e), !nr(e) && ((L.cursor = L.limit - e), !tr(e)))) {
                            if (((L.cursor = L.limit - e), (L.ket = L.cursor), A() && L.find_among_b(l, 4)))
                                return (
                                    (L.bra = L.cursor),
                                    L.slice_del(),
                                    (L.ket = L.cursor),
                                    (i = L.limit - L.cursor),
                                    void (B()
                                        ? ((L.bra = L.cursor),
                                          L.slice_del(),
                                          (L.ket = L.cursor),
                                          Q() && ((L.bra = L.cursor), L.slice_del(), er()))
                                        : ((L.cursor = L.limit - i),
                                          Q() ? ((L.bra = L.cursor), L.slice_del()) : (L.cursor = L.limit - i),
                                          er()))
                                )
                            if (((L.cursor = L.limit - e), !ur())) {
                                if (((L.cursor = L.limit - e), G())) return (L.bra = L.cursor), void L.slice_del()
                                ;(L.cursor = L.limit - e),
                                    er() ||
                                        ((L.cursor = L.limit - e),
                                        or() ||
                                            ((L.cursor = L.limit - e),
                                            (L.ket = L.cursor),
                                            (B() || ((L.cursor = L.limit - e), D())) &&
                                                ((L.bra = L.cursor),
                                                L.slice_del(),
                                                (L.ket = L.cursor),
                                                Q() && ((L.bra = L.cursor), L.slice_del(), er()))))
                            }
                        }
                    }
                    function cr(r, i, e) {
                        if (
                            ((L.cursor = L.limit - r),
                            (function () {
                                for (;;) {
                                    var r = L.limit - L.cursor
                                    if (L.in_grouping_b(C, 97, 305)) {
                                        L.cursor = L.limit - r
                                        break
                                    }
                                    if (((L.cursor = L.limit - r), L.cursor <= L.limit_backward)) return !1
                                    L.cursor--
                                }
                                return !0
                            })())
                        ) {
                            var n = L.limit - L.cursor
                            if (!L.eq_s_b(1, i) && ((L.cursor = L.limit - n), !L.eq_s_b(1, e))) return !0
                            L.cursor = L.limit - r
                            var t = L.cursor
                            return L.insert(L.cursor, L.cursor, e), (L.cursor = t), !1
                        }
                        return !0
                    }
                    function lr(r, i, e) {
                        for (; !L.eq_s(i, e); ) {
                            if (L.cursor >= L.limit) return !0
                            L.cursor++
                        }
                        return i != L.limit || ((L.cursor = r), !1)
                    }
                    function ar() {
                        var r,
                            i,
                            e = L.cursor
                        return (
                            !(!lr((r = L.cursor), 2, 'ad') || !lr((L.cursor = r), 5, 'soyad')) &&
                            ((L.limit_backward = e),
                            (L.cursor = L.limit),
                            (i = L.limit - L.cursor),
                            (L.eq_s_b(1, 'd') || ((L.cursor = L.limit - i), L.eq_s_b(1, 'g'))) &&
                                cr(i, 'a', 'ı') &&
                                cr(i, 'e', 'i') &&
                                cr(i, 'o', 'u') &&
                                cr(i, 'ö', 'ü'),
                            (L.cursor = L.limit),
                            (function () {
                                var r
                                if (((L.ket = L.cursor), (r = L.find_among_b(q, 4))))
                                    switch (((L.bra = L.cursor), r)) {
                                        case 1:
                                            L.slice_from('p')
                                            break
                                        case 2:
                                            L.slice_from('ç')
                                            break
                                        case 3:
                                            L.slice_from('t')
                                            break
                                        case 4:
                                            L.slice_from('k')
                                    }
                            })(),
                            !0)
                        )
                    }
                    ;(this.setCurrent = function (r) {
                        L.setCurrent(r)
                    }),
                        (this.getCurrent = function () {
                            return L.getCurrent()
                        }),
                        (this.stem = function () {
                            return !!(
                                (function () {
                                    for (var r, i = L.cursor, e = 2; ; ) {
                                        for (r = L.cursor; !L.in_grouping(C, 97, 305); ) {
                                            if (L.cursor >= L.limit)
                                                return (L.cursor = r), !(0 < e || ((L.cursor = i), 0))
                                            L.cursor++
                                        }
                                        e--
                                    }
                                })() &&
                                ((L.limit_backward = L.cursor),
                                (L.cursor = L.limit),
                                ir(),
                                (L.cursor = L.limit),
                                t && (sr(), (L.cursor = L.limit_backward), ar()))
                            )
                        })
                })()),
                function (r) {
                    return 'function' == typeof r.update
                        ? r.update(function (r) {
                              return i.setCurrent(r), i.stem(), i.getCurrent()
                          })
                        : (i.setCurrent(r), i.stem(), i.getCurrent())
                })),
            r.Pipeline.registerFunction(r.tr.stemmer, 'stemmer-tr'),
            (r.tr.stopWordFilter = r.generateStopWordFilter(
                'acaba altmış altı ama ancak arada aslında ayrıca bana bazı belki ben benden beni benim beri beş bile bin bir biri birkaç birkez birçok birşey birşeyi biz bizden bize bizi bizim bu buna bunda bundan bunlar bunları bunların bunu bunun burada böyle böylece da daha dahi de defa değil diye diğer doksan dokuz dolayı dolayısıyla dört edecek eden ederek edilecek ediliyor edilmesi ediyor elli en etmesi etti ettiği ettiğini eğer gibi göre halen hangi hatta hem henüz hep hepsi her herhangi herkesin hiç hiçbir iki ile ilgili ise itibaren itibariyle için işte kadar karşın katrilyon kendi kendilerine kendini kendisi kendisine kendisini kez ki kim kimden kime kimi kimse kırk milyar milyon mu mü mı nasıl ne neden nedenle nerde nerede nereye niye niçin o olan olarak oldu olduklarını olduğu olduğunu olmadı olmadığı olmak olması olmayan olmaz olsa olsun olup olur olursa oluyor on ona ondan onlar onlardan onları onların onu onun otuz oysa pek rağmen sadece sanki sekiz seksen sen senden seni senin siz sizden sizi sizin tarafından trilyon tüm var vardı ve veya ya yani yapacak yapmak yaptı yaptıkları yaptığı yaptığını yapılan yapılması yapıyor yedi yerine yetmiş yine yirmi yoksa yüz zaten çok çünkü öyle üzere üç şey şeyden şeyi şeyler şu şuna şunda şundan şunları şunu şöyle'.split(
                    ' '
                )
            )),
            r.Pipeline.registerFunction(r.tr.stopWordFilter, 'stopWordFilter-tr')
    }
})
