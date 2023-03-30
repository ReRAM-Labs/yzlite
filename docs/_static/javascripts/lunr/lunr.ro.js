!(function (e, i) {
    'function' == typeof define && define.amd
        ? define(i)
        : 'object' == typeof exports
        ? (module.exports = i())
        : i()(e.lunr)
})(this, function () {
    return function (e) {
        if (void 0 === e) throw new Error('Lunr is not present. Please include / require Lunr before this script.')
        if (void 0 === e.stemmerSupport)
            throw new Error(
                'Lunr stemmer support is not present. Please include / require Lunr stemmer support before this script.'
            )
        var h, z, i
        ;(e.ro = function () {
            this.pipeline.reset(),
                this.pipeline.add(e.ro.trimmer, e.ro.stopWordFilter, e.ro.stemmer),
                this.searchPipeline && (this.searchPipeline.reset(), this.searchPipeline.add(e.ro.stemmer))
        }),
            (e.ro.wordCharacters =
                'A-Za-zªºÀ-ÖØ-öø-ʸˠ-ˤᴀ-ᴥᴬ-ᵜᵢ-ᵥᵫ-ᵷᵹ-ᶾḀ-ỿⁱⁿₐ-ₜKÅℲⅎⅠ-ↈⱠ-ⱿꜢ-ꞇꞋ-ꞭꞰ-ꞷꟷ-ꟿꬰ-ꭚꭜ-ꭤﬀ-ﬆＡ-Ｚａ-ｚ'),
            (e.ro.trimmer = e.trimmerSupport.generateTrimmer(e.ro.wordCharacters)),
            e.Pipeline.registerFunction(e.ro.trimmer, 'trimmer-ro'),
            (e.ro.stemmer =
                ((h = e.stemmerSupport.Among),
                (z = e.stemmerSupport.SnowballProgram),
                (i = new (function () {
                    var r,
                        n,
                        t,
                        a,
                        o = [new h('', -1, 3), new h('I', 0, 1), new h('U', 0, 2)],
                        s = [
                            new h('ea', -1, 3),
                            new h('aţia', -1, 7),
                            new h('aua', -1, 2),
                            new h('iua', -1, 4),
                            new h('aţie', -1, 7),
                            new h('ele', -1, 3),
                            new h('ile', -1, 5),
                            new h('iile', 6, 4),
                            new h('iei', -1, 4),
                            new h('atei', -1, 6),
                            new h('ii', -1, 4),
                            new h('ului', -1, 1),
                            new h('ul', -1, 1),
                            new h('elor', -1, 3),
                            new h('ilor', -1, 4),
                            new h('iilor', 14, 4)
                        ],
                        c = [
                            new h('icala', -1, 4),
                            new h('iciva', -1, 4),
                            new h('ativa', -1, 5),
                            new h('itiva', -1, 6),
                            new h('icale', -1, 4),
                            new h('aţiune', -1, 5),
                            new h('iţiune', -1, 6),
                            new h('atoare', -1, 5),
                            new h('itoare', -1, 6),
                            new h('ătoare', -1, 5),
                            new h('icitate', -1, 4),
                            new h('abilitate', -1, 1),
                            new h('ibilitate', -1, 2),
                            new h('ivitate', -1, 3),
                            new h('icive', -1, 4),
                            new h('ative', -1, 5),
                            new h('itive', -1, 6),
                            new h('icali', -1, 4),
                            new h('atori', -1, 5),
                            new h('icatori', 18, 4),
                            new h('itori', -1, 6),
                            new h('ători', -1, 5),
                            new h('icitati', -1, 4),
                            new h('abilitati', -1, 1),
                            new h('ivitati', -1, 3),
                            new h('icivi', -1, 4),
                            new h('ativi', -1, 5),
                            new h('itivi', -1, 6),
                            new h('icităi', -1, 4),
                            new h('abilităi', -1, 1),
                            new h('ivităi', -1, 3),
                            new h('icităţi', -1, 4),
                            new h('abilităţi', -1, 1),
                            new h('ivităţi', -1, 3),
                            new h('ical', -1, 4),
                            new h('ator', -1, 5),
                            new h('icator', 35, 4),
                            new h('itor', -1, 6),
                            new h('ător', -1, 5),
                            new h('iciv', -1, 4),
                            new h('ativ', -1, 5),
                            new h('itiv', -1, 6),
                            new h('icală', -1, 4),
                            new h('icivă', -1, 4),
                            new h('ativă', -1, 5),
                            new h('itivă', -1, 6)
                        ],
                        u = [
                            new h('ica', -1, 1),
                            new h('abila', -1, 1),
                            new h('ibila', -1, 1),
                            new h('oasa', -1, 1),
                            new h('ata', -1, 1),
                            new h('ita', -1, 1),
                            new h('anta', -1, 1),
                            new h('ista', -1, 3),
                            new h('uta', -1, 1),
                            new h('iva', -1, 1),
                            new h('ic', -1, 1),
                            new h('ice', -1, 1),
                            new h('abile', -1, 1),
                            new h('ibile', -1, 1),
                            new h('isme', -1, 3),
                            new h('iune', -1, 2),
                            new h('oase', -1, 1),
                            new h('ate', -1, 1),
                            new h('itate', 17, 1),
                            new h('ite', -1, 1),
                            new h('ante', -1, 1),
                            new h('iste', -1, 3),
                            new h('ute', -1, 1),
                            new h('ive', -1, 1),
                            new h('ici', -1, 1),
                            new h('abili', -1, 1),
                            new h('ibili', -1, 1),
                            new h('iuni', -1, 2),
                            new h('atori', -1, 1),
                            new h('osi', -1, 1),
                            new h('ati', -1, 1),
                            new h('itati', 30, 1),
                            new h('iti', -1, 1),
                            new h('anti', -1, 1),
                            new h('isti', -1, 3),
                            new h('uti', -1, 1),
                            new h('işti', -1, 3),
                            new h('ivi', -1, 1),
                            new h('ităi', -1, 1),
                            new h('oşi', -1, 1),
                            new h('ităţi', -1, 1),
                            new h('abil', -1, 1),
                            new h('ibil', -1, 1),
                            new h('ism', -1, 3),
                            new h('ator', -1, 1),
                            new h('os', -1, 1),
                            new h('at', -1, 1),
                            new h('it', -1, 1),
                            new h('ant', -1, 1),
                            new h('ist', -1, 3),
                            new h('ut', -1, 1),
                            new h('iv', -1, 1),
                            new h('ică', -1, 1),
                            new h('abilă', -1, 1),
                            new h('ibilă', -1, 1),
                            new h('oasă', -1, 1),
                            new h('ată', -1, 1),
                            new h('ită', -1, 1),
                            new h('antă', -1, 1),
                            new h('istă', -1, 3),
                            new h('ută', -1, 1),
                            new h('ivă', -1, 1)
                        ],
                        w = [
                            new h('ea', -1, 1),
                            new h('ia', -1, 1),
                            new h('esc', -1, 1),
                            new h('ăsc', -1, 1),
                            new h('ind', -1, 1),
                            new h('ând', -1, 1),
                            new h('are', -1, 1),
                            new h('ere', -1, 1),
                            new h('ire', -1, 1),
                            new h('âre', -1, 1),
                            new h('se', -1, 2),
                            new h('ase', 10, 1),
                            new h('sese', 10, 2),
                            new h('ise', 10, 1),
                            new h('use', 10, 1),
                            new h('âse', 10, 1),
                            new h('eşte', -1, 1),
                            new h('ăşte', -1, 1),
                            new h('eze', -1, 1),
                            new h('ai', -1, 1),
                            new h('eai', 19, 1),
                            new h('iai', 19, 1),
                            new h('sei', -1, 2),
                            new h('eşti', -1, 1),
                            new h('ăşti', -1, 1),
                            new h('ui', -1, 1),
                            new h('ezi', -1, 1),
                            new h('âi', -1, 1),
                            new h('aşi', -1, 1),
                            new h('seşi', -1, 2),
                            new h('aseşi', 29, 1),
                            new h('seseşi', 29, 2),
                            new h('iseşi', 29, 1),
                            new h('useşi', 29, 1),
                            new h('âseşi', 29, 1),
                            new h('işi', -1, 1),
                            new h('uşi', -1, 1),
                            new h('âşi', -1, 1),
                            new h('aţi', -1, 2),
                            new h('eaţi', 38, 1),
                            new h('iaţi', 38, 1),
                            new h('eţi', -1, 2),
                            new h('iţi', -1, 2),
                            new h('âţi', -1, 2),
                            new h('arăţi', -1, 1),
                            new h('serăţi', -1, 2),
                            new h('aserăţi', 45, 1),
                            new h('seserăţi', 45, 2),
                            new h('iserăţi', 45, 1),
                            new h('userăţi', 45, 1),
                            new h('âserăţi', 45, 1),
                            new h('irăţi', -1, 1),
                            new h('urăţi', -1, 1),
                            new h('ârăţi', -1, 1),
                            new h('am', -1, 1),
                            new h('eam', 54, 1),
                            new h('iam', 54, 1),
                            new h('em', -1, 2),
                            new h('asem', 57, 1),
                            new h('sesem', 57, 2),
                            new h('isem', 57, 1),
                            new h('usem', 57, 1),
                            new h('âsem', 57, 1),
                            new h('im', -1, 2),
                            new h('âm', -1, 2),
                            new h('ăm', -1, 2),
                            new h('arăm', 65, 1),
                            new h('serăm', 65, 2),
                            new h('aserăm', 67, 1),
                            new h('seserăm', 67, 2),
                            new h('iserăm', 67, 1),
                            new h('userăm', 67, 1),
                            new h('âserăm', 67, 1),
                            new h('irăm', 65, 1),
                            new h('urăm', 65, 1),
                            new h('ârăm', 65, 1),
                            new h('au', -1, 1),
                            new h('eau', 76, 1),
                            new h('iau', 76, 1),
                            new h('indu', -1, 1),
                            new h('ându', -1, 1),
                            new h('ez', -1, 1),
                            new h('ească', -1, 1),
                            new h('ară', -1, 1),
                            new h('seră', -1, 2),
                            new h('aseră', 84, 1),
                            new h('seseră', 84, 2),
                            new h('iseră', 84, 1),
                            new h('useră', 84, 1),
                            new h('âseră', 84, 1),
                            new h('iră', -1, 1),
                            new h('ură', -1, 1),
                            new h('âră', -1, 1),
                            new h('ează', -1, 1)
                        ],
                        i = [
                            new h('a', -1, 1),
                            new h('e', -1, 1),
                            new h('ie', 1, 1),
                            new h('i', -1, 1),
                            new h('ă', -1, 1)
                        ],
                        m = [17, 65, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 32, 0, 0, 4],
                        l = new z()
                    function f(e, i) {
                        l.eq_s(1, e) && ((l.ket = l.cursor), l.in_grouping(m, 97, 259) && l.slice_from(i))
                    }
                    function p() {
                        if (l.out_grouping(m, 97, 259)) {
                            for (; !l.in_grouping(m, 97, 259); ) {
                                if (l.cursor >= l.limit) return !0
                                l.cursor++
                            }
                            return !1
                        }
                        return !0
                    }
                    function d() {
                        var e,
                            i,
                            r = l.cursor
                        if (l.in_grouping(m, 97, 259)) {
                            if (((e = l.cursor), !p())) return void (a = l.cursor)
                            if (
                                ((l.cursor = e),
                                !(function () {
                                    if (l.in_grouping(m, 97, 259))
                                        for (; !l.out_grouping(m, 97, 259); ) {
                                            if (l.cursor >= l.limit) return !0
                                            l.cursor++
                                        }
                                    return !1
                                })())
                            )
                                return void (a = l.cursor)
                        }
                        ;(l.cursor = r),
                            l.out_grouping(m, 97, 259) &&
                                ((i = l.cursor),
                                p() && ((l.cursor = i), l.in_grouping(m, 97, 259) && l.cursor < l.limit && l.cursor++),
                                (a = l.cursor))
                    }
                    function b() {
                        for (; !l.in_grouping(m, 97, 259); ) {
                            if (l.cursor >= l.limit) return !1
                            l.cursor++
                        }
                        for (; !l.out_grouping(m, 97, 259); ) {
                            if (l.cursor >= l.limit) return !1
                            l.cursor++
                        }
                        return !0
                    }
                    function v() {
                        return t <= l.cursor
                    }
                    function _() {
                        var e,
                            i = l.limit - l.cursor
                        if (((l.ket = l.cursor), (e = l.find_among_b(c, 46)) && ((l.bra = l.cursor), v()))) {
                            switch (e) {
                                case 1:
                                    l.slice_from('abil')
                                    break
                                case 2:
                                    l.slice_from('ibil')
                                    break
                                case 3:
                                    l.slice_from('iv')
                                    break
                                case 4:
                                    l.slice_from('ic')
                                    break
                                case 5:
                                    l.slice_from('at')
                                    break
                                case 6:
                                    l.slice_from('it')
                            }
                            return (r = !0), (l.cursor = l.limit - i), !0
                        }
                        return !1
                    }
                    function g() {
                        var e, i
                        for (r = !1; ; )
                            if (((i = l.limit - l.cursor), !_())) {
                                l.cursor = l.limit - i
                                break
                            }
                        if (((l.ket = l.cursor), (e = l.find_among_b(u, 62)) && ((l.bra = l.cursor), n <= l.cursor))) {
                            switch (e) {
                                case 1:
                                    l.slice_del()
                                    break
                                case 2:
                                    l.eq_s_b(1, 'ţ') && ((l.bra = l.cursor), l.slice_from('t'))
                                    break
                                case 3:
                                    l.slice_from('ist')
                            }
                            r = !0
                        }
                    }
                    function k() {
                        var e
                        ;(l.ket = l.cursor),
                            (e = l.find_among_b(i, 5)) && ((l.bra = l.cursor), a <= l.cursor && 1 == e && l.slice_del())
                    }
                    ;(this.setCurrent = function (e) {
                        l.setCurrent(e)
                    }),
                        (this.getCurrent = function () {
                            return l.getCurrent()
                        }),
                        (this.stem = function () {
                            var e,
                                i = l.cursor
                            return (
                                (function () {
                                    for (
                                        var e, i;
                                        (e = l.cursor),
                                            l.in_grouping(m, 97, 259) &&
                                                ((i = l.cursor), (l.bra = i), f('u', 'U'), (l.cursor = i), f('i', 'I')),
                                            (l.cursor = e),
                                            !(l.cursor >= l.limit);

                                    )
                                        l.cursor++
                                })(),
                                (l.cursor = i),
                                (e = l.cursor),
                                (a = l.limit),
                                (n = t = a),
                                d(),
                                (l.cursor = e),
                                b() && ((t = l.cursor), b() && (n = l.cursor)),
                                (l.limit_backward = i),
                                (l.cursor = l.limit),
                                (function () {
                                    var e, i
                                    if (((l.ket = l.cursor), (e = l.find_among_b(s, 16)) && ((l.bra = l.cursor), v())))
                                        switch (e) {
                                            case 1:
                                                l.slice_del()
                                                break
                                            case 2:
                                                l.slice_from('a')
                                                break
                                            case 3:
                                                l.slice_from('e')
                                                break
                                            case 4:
                                                l.slice_from('i')
                                                break
                                            case 5:
                                                ;(i = l.limit - l.cursor),
                                                    l.eq_s_b(2, 'ab') || ((l.cursor = l.limit - i), l.slice_from('i'))
                                                break
                                            case 6:
                                                l.slice_from('at')
                                                break
                                            case 7:
                                                l.slice_from('aţi')
                                        }
                                })(),
                                (l.cursor = l.limit),
                                g(),
                                (l.cursor = l.limit),
                                r ||
                                    ((l.cursor = l.limit),
                                    (function () {
                                        var e, i, r
                                        if (l.cursor >= a) {
                                            if (
                                                ((i = l.limit_backward),
                                                (l.limit_backward = a),
                                                (l.ket = l.cursor),
                                                (e = l.find_among_b(w, 94)))
                                            )
                                                switch (((l.bra = l.cursor), e)) {
                                                    case 1:
                                                        if (
                                                            ((r = l.limit - l.cursor),
                                                            !l.out_grouping_b(m, 97, 259) &&
                                                                ((l.cursor = l.limit - r), !l.eq_s_b(1, 'u')))
                                                        )
                                                            break
                                                    case 2:
                                                        l.slice_del()
                                                }
                                            l.limit_backward = i
                                        }
                                    })(),
                                    (l.cursor = l.limit)),
                                k(),
                                (l.cursor = l.limit_backward),
                                (function () {
                                    for (var e; ; ) {
                                        if (((l.bra = l.cursor), (e = l.find_among(o, 3))))
                                            switch (((l.ket = l.cursor), e)) {
                                                case 1:
                                                    l.slice_from('i')
                                                    continue
                                                case 2:
                                                    l.slice_from('u')
                                                    continue
                                                case 3:
                                                    if (l.cursor >= l.limit) break
                                                    l.cursor++
                                                    continue
                                            }
                                        break
                                    }
                                })(),
                                !0
                            )
                        })
                })()),
                function (e) {
                    return 'function' == typeof e.update
                        ? e.update(function (e) {
                              return i.setCurrent(e), i.stem(), i.getCurrent()
                          })
                        : (i.setCurrent(e), i.stem(), i.getCurrent())
                })),
            e.Pipeline.registerFunction(e.ro.stemmer, 'stemmer-ro'),
            (e.ro.stopWordFilter = e.generateStopWordFilter(
                'acea aceasta această aceea acei aceia acel acela acele acelea acest acesta aceste acestea aceşti aceştia acolo acord acum ai aia aibă aici al ale alea altceva altcineva am ar are asemenea asta astea astăzi asupra au avea avem aveţi azi aş aşadar aţi bine bucur bună ca care caut ce cel ceva chiar cinci cine cineva contra cu cum cumva curând curînd când cât câte câtva câţi cînd cît cîte cîtva cîţi că căci cărei căror cărui către da dacă dar datorită dată dau de deci deja deoarece departe deşi din dinaintea dintr- dintre doi doilea două drept după dă ea ei el ele eram este eu eşti face fata fi fie fiecare fii fim fiu fiţi frumos fără graţie halbă iar ieri la le li lor lui lângă lîngă mai mea mei mele mereu meu mi mie mine mult multă mulţi mulţumesc mâine mîine mă ne nevoie nici nicăieri nimeni nimeri nimic nişte noastre noastră noi noroc nostru nouă noştri nu opt ori oricare orice oricine oricum oricând oricât oricînd oricît oriunde patra patru patrulea pe pentru peste pic poate pot prea prima primul prin puţin puţina puţină până pînă rog sa sale sau se spate spre sub sunt suntem sunteţi sută sînt sîntem sînteţi să săi său ta tale te timp tine toate toată tot totuşi toţi trei treia treilea tu tăi tău un una unde undeva unei uneia unele uneori unii unor unora unu unui unuia unul vi voastre voastră voi vostru vouă voştri vreme vreo vreun vă zece zero zi zice îi îl îmi împotriva în  înainte înaintea încotro încât încît între întrucât întrucît îţi ăla ălea ăsta ăstea ăştia şapte şase şi ştiu ţi ţie'.split(
                    ' '
                )
            )),
            e.Pipeline.registerFunction(e.ro.stopWordFilter, 'stopWordFilter-ro')
    }
})
