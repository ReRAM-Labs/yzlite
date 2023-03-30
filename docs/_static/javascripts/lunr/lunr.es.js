!(function (e, s) {
    'function' == typeof define && define.amd
        ? define(s)
        : 'object' == typeof exports
        ? (module.exports = s())
        : s()(e.lunr)
})(this, function () {
    return function (e) {
        if (void 0 === e) throw new Error('Lunr is not present. Please include / require Lunr before this script.')
        if (void 0 === e.stemmerSupport)
            throw new Error(
                'Lunr stemmer support is not present. Please include / require Lunr stemmer support before this script.'
            )
        var C, P, s
        ;(e.es = function () {
            this.pipeline.reset(),
                this.pipeline.add(e.es.trimmer, e.es.stopWordFilter, e.es.stemmer),
                this.searchPipeline && (this.searchPipeline.reset(), this.searchPipeline.add(e.es.stemmer))
        }),
            (e.es.wordCharacters =
                'A-Za-zªºÀ-ÖØ-öø-ʸˠ-ˤᴀ-ᴥᴬ-ᵜᵢ-ᵥᵫ-ᵷᵹ-ᶾḀ-ỿⁱⁿₐ-ₜKÅℲⅎⅠ-ↈⱠ-ⱿꜢ-ꞇꞋ-ꞭꞰ-ꞷꟷ-ꟿꬰ-ꭚꭜ-ꭤﬀ-ﬆＡ-Ｚａ-ｚ'),
            (e.es.trimmer = e.trimmerSupport.generateTrimmer(e.es.wordCharacters)),
            e.Pipeline.registerFunction(e.es.trimmer, 'trimmer-es'),
            (e.es.stemmer =
                ((C = e.stemmerSupport.Among),
                (P = e.stemmerSupport.SnowballProgram),
                (s = new (function () {
                    var r,
                        n,
                        i,
                        a = [
                            new C('', -1, 6),
                            new C('á', 0, 1),
                            new C('é', 0, 2),
                            new C('í', 0, 3),
                            new C('ó', 0, 4),
                            new C('ú', 0, 5)
                        ],
                        t = [
                            new C('la', -1, -1),
                            new C('sela', 0, -1),
                            new C('le', -1, -1),
                            new C('me', -1, -1),
                            new C('se', -1, -1),
                            new C('lo', -1, -1),
                            new C('selo', 5, -1),
                            new C('las', -1, -1),
                            new C('selas', 7, -1),
                            new C('les', -1, -1),
                            new C('los', -1, -1),
                            new C('selos', 10, -1),
                            new C('nos', -1, -1)
                        ],
                        o = [
                            new C('ando', -1, 6),
                            new C('iendo', -1, 6),
                            new C('yendo', -1, 7),
                            new C('ándo', -1, 2),
                            new C('iéndo', -1, 1),
                            new C('ar', -1, 6),
                            new C('er', -1, 6),
                            new C('ir', -1, 6),
                            new C('ár', -1, 3),
                            new C('ér', -1, 4),
                            new C('ír', -1, 5)
                        ],
                        s = [new C('ic', -1, -1), new C('ad', -1, -1), new C('os', -1, -1), new C('iv', -1, 1)],
                        u = [new C('able', -1, 1), new C('ible', -1, 1), new C('ante', -1, 1)],
                        w = [new C('ic', -1, 1), new C('abil', -1, 1), new C('iv', -1, 1)],
                        c = [
                            new C('ica', -1, 1),
                            new C('ancia', -1, 2),
                            new C('encia', -1, 5),
                            new C('adora', -1, 2),
                            new C('osa', -1, 1),
                            new C('ista', -1, 1),
                            new C('iva', -1, 9),
                            new C('anza', -1, 1),
                            new C('logía', -1, 3),
                            new C('idad', -1, 8),
                            new C('able', -1, 1),
                            new C('ible', -1, 1),
                            new C('ante', -1, 2),
                            new C('mente', -1, 7),
                            new C('amente', 13, 6),
                            new C('ación', -1, 2),
                            new C('ución', -1, 4),
                            new C('ico', -1, 1),
                            new C('ismo', -1, 1),
                            new C('oso', -1, 1),
                            new C('amiento', -1, 1),
                            new C('imiento', -1, 1),
                            new C('ivo', -1, 9),
                            new C('ador', -1, 2),
                            new C('icas', -1, 1),
                            new C('ancias', -1, 2),
                            new C('encias', -1, 5),
                            new C('adoras', -1, 2),
                            new C('osas', -1, 1),
                            new C('istas', -1, 1),
                            new C('ivas', -1, 9),
                            new C('anzas', -1, 1),
                            new C('logías', -1, 3),
                            new C('idades', -1, 8),
                            new C('ables', -1, 1),
                            new C('ibles', -1, 1),
                            new C('aciones', -1, 2),
                            new C('uciones', -1, 4),
                            new C('adores', -1, 2),
                            new C('antes', -1, 2),
                            new C('icos', -1, 1),
                            new C('ismos', -1, 1),
                            new C('osos', -1, 1),
                            new C('amientos', -1, 1),
                            new C('imientos', -1, 1),
                            new C('ivos', -1, 9)
                        ],
                        m = [
                            new C('ya', -1, 1),
                            new C('ye', -1, 1),
                            new C('yan', -1, 1),
                            new C('yen', -1, 1),
                            new C('yeron', -1, 1),
                            new C('yendo', -1, 1),
                            new C('yo', -1, 1),
                            new C('yas', -1, 1),
                            new C('yes', -1, 1),
                            new C('yais', -1, 1),
                            new C('yamos', -1, 1),
                            new C('yó', -1, 1)
                        ],
                        l = [
                            new C('aba', -1, 2),
                            new C('ada', -1, 2),
                            new C('ida', -1, 2),
                            new C('ara', -1, 2),
                            new C('iera', -1, 2),
                            new C('ía', -1, 2),
                            new C('aría', 5, 2),
                            new C('ería', 5, 2),
                            new C('iría', 5, 2),
                            new C('ad', -1, 2),
                            new C('ed', -1, 2),
                            new C('id', -1, 2),
                            new C('ase', -1, 2),
                            new C('iese', -1, 2),
                            new C('aste', -1, 2),
                            new C('iste', -1, 2),
                            new C('an', -1, 2),
                            new C('aban', 16, 2),
                            new C('aran', 16, 2),
                            new C('ieran', 16, 2),
                            new C('ían', 16, 2),
                            new C('arían', 20, 2),
                            new C('erían', 20, 2),
                            new C('irían', 20, 2),
                            new C('en', -1, 1),
                            new C('asen', 24, 2),
                            new C('iesen', 24, 2),
                            new C('aron', -1, 2),
                            new C('ieron', -1, 2),
                            new C('arán', -1, 2),
                            new C('erán', -1, 2),
                            new C('irán', -1, 2),
                            new C('ado', -1, 2),
                            new C('ido', -1, 2),
                            new C('ando', -1, 2),
                            new C('iendo', -1, 2),
                            new C('ar', -1, 2),
                            new C('er', -1, 2),
                            new C('ir', -1, 2),
                            new C('as', -1, 2),
                            new C('abas', 39, 2),
                            new C('adas', 39, 2),
                            new C('idas', 39, 2),
                            new C('aras', 39, 2),
                            new C('ieras', 39, 2),
                            new C('ías', 39, 2),
                            new C('arías', 45, 2),
                            new C('erías', 45, 2),
                            new C('irías', 45, 2),
                            new C('es', -1, 1),
                            new C('ases', 49, 2),
                            new C('ieses', 49, 2),
                            new C('abais', -1, 2),
                            new C('arais', -1, 2),
                            new C('ierais', -1, 2),
                            new C('íais', -1, 2),
                            new C('aríais', 55, 2),
                            new C('eríais', 55, 2),
                            new C('iríais', 55, 2),
                            new C('aseis', -1, 2),
                            new C('ieseis', -1, 2),
                            new C('asteis', -1, 2),
                            new C('isteis', -1, 2),
                            new C('áis', -1, 2),
                            new C('éis', -1, 1),
                            new C('aréis', 64, 2),
                            new C('eréis', 64, 2),
                            new C('iréis', 64, 2),
                            new C('ados', -1, 2),
                            new C('idos', -1, 2),
                            new C('amos', -1, 2),
                            new C('ábamos', 70, 2),
                            new C('áramos', 70, 2),
                            new C('iéramos', 70, 2),
                            new C('íamos', 70, 2),
                            new C('aríamos', 74, 2),
                            new C('eríamos', 74, 2),
                            new C('iríamos', 74, 2),
                            new C('emos', -1, 1),
                            new C('aremos', 78, 2),
                            new C('eremos', 78, 2),
                            new C('iremos', 78, 2),
                            new C('ásemos', 78, 2),
                            new C('iésemos', 78, 2),
                            new C('imos', -1, 2),
                            new C('arás', -1, 2),
                            new C('erás', -1, 2),
                            new C('irás', -1, 2),
                            new C('ís', -1, 2),
                            new C('ará', -1, 2),
                            new C('erá', -1, 2),
                            new C('irá', -1, 2),
                            new C('aré', -1, 2),
                            new C('eré', -1, 2),
                            new C('iré', -1, 2),
                            new C('ió', -1, 2)
                        ],
                        d = [
                            new C('a', -1, 1),
                            new C('e', -1, 2),
                            new C('o', -1, 1),
                            new C('os', -1, 1),
                            new C('á', -1, 1),
                            new C('é', -1, 2),
                            new C('í', -1, 1),
                            new C('ó', -1, 1)
                        ],
                        b = [17, 65, 16, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 17, 4, 10],
                        f = new P()
                    function _() {
                        if (f.out_grouping(b, 97, 252)) {
                            for (; !f.in_grouping(b, 97, 252); ) {
                                if (f.cursor >= f.limit) return !0
                                f.cursor++
                            }
                            return !1
                        }
                        return !0
                    }
                    function h() {
                        var e,
                            s = f.cursor
                        if (
                            (function () {
                                if (f.in_grouping(b, 97, 252)) {
                                    var e = f.cursor
                                    if (_()) {
                                        if (((f.cursor = e), !f.in_grouping(b, 97, 252))) return !0
                                        for (; !f.out_grouping(b, 97, 252); ) {
                                            if (f.cursor >= f.limit) return !0
                                            f.cursor++
                                        }
                                    }
                                    return !1
                                }
                                return !0
                            })()
                        ) {
                            if (((f.cursor = s), !f.out_grouping(b, 97, 252))) return
                            if (((e = f.cursor), _())) {
                                if (((f.cursor = e), !f.in_grouping(b, 97, 252) || f.cursor >= f.limit)) return
                                f.cursor++
                            }
                        }
                        i = f.cursor
                    }
                    function v() {
                        for (; !f.in_grouping(b, 97, 252); ) {
                            if (f.cursor >= f.limit) return !1
                            f.cursor++
                        }
                        for (; !f.out_grouping(b, 97, 252); ) {
                            if (f.cursor >= f.limit) return !1
                            f.cursor++
                        }
                        return !0
                    }
                    function p() {
                        return i <= f.cursor
                    }
                    function g() {
                        return r <= f.cursor
                    }
                    function k(e, s) {
                        if (!g()) return !0
                        f.slice_del(), (f.ket = f.cursor)
                        var r = f.find_among_b(e, s)
                        return r && ((f.bra = f.cursor), 1 == r && g() && f.slice_del()), !1
                    }
                    function y(e) {
                        return (
                            !g() ||
                            (f.slice_del(),
                            (f.ket = f.cursor),
                            f.eq_s_b(2, e) && ((f.bra = f.cursor), g() && f.slice_del()),
                            !1)
                        )
                    }
                    function q() {
                        var e
                        if (((f.ket = f.cursor), (e = f.find_among_b(c, 46)))) {
                            switch (((f.bra = f.cursor), e)) {
                                case 1:
                                    if (!g()) return !1
                                    f.slice_del()
                                    break
                                case 2:
                                    if (y('ic')) return !1
                                    break
                                case 3:
                                    if (!g()) return !1
                                    f.slice_from('log')
                                    break
                                case 4:
                                    if (!g()) return !1
                                    f.slice_from('u')
                                    break
                                case 5:
                                    if (!g()) return !1
                                    f.slice_from('ente')
                                    break
                                case 6:
                                    if (!(n <= f.cursor)) return !1
                                    f.slice_del(),
                                        (f.ket = f.cursor),
                                        (e = f.find_among_b(s, 4)) &&
                                            ((f.bra = f.cursor),
                                            g() &&
                                                (f.slice_del(),
                                                1 == e &&
                                                    ((f.ket = f.cursor),
                                                    f.eq_s_b(2, 'at') && ((f.bra = f.cursor), g() && f.slice_del()))))
                                    break
                                case 7:
                                    if (k(u, 3)) return !1
                                    break
                                case 8:
                                    if (k(w, 3)) return !1
                                    break
                                case 9:
                                    if (y('at')) return !1
                            }
                            return !0
                        }
                        return !1
                    }
                    ;(this.setCurrent = function (e) {
                        f.setCurrent(e)
                    }),
                        (this.getCurrent = function () {
                            return f.getCurrent()
                        }),
                        (this.stem = function () {
                            var e,
                                s = f.cursor
                            return (
                                (e = f.cursor),
                                (i = f.limit),
                                (r = n = i),
                                h(),
                                (f.cursor = e),
                                v() && ((n = f.cursor), v() && (r = f.cursor)),
                                (f.limit_backward = s),
                                (f.cursor = f.limit),
                                (function () {
                                    var e
                                    if (
                                        ((f.ket = f.cursor),
                                        f.find_among_b(t, 13) &&
                                            ((f.bra = f.cursor), (e = f.find_among_b(o, 11)) && p()))
                                    )
                                        switch (e) {
                                            case 1:
                                                ;(f.bra = f.cursor), f.slice_from('iendo')
                                                break
                                            case 2:
                                                ;(f.bra = f.cursor), f.slice_from('ando')
                                                break
                                            case 3:
                                                ;(f.bra = f.cursor), f.slice_from('ar')
                                                break
                                            case 4:
                                                ;(f.bra = f.cursor), f.slice_from('er')
                                                break
                                            case 5:
                                                ;(f.bra = f.cursor), f.slice_from('ir')
                                                break
                                            case 6:
                                                f.slice_del()
                                                break
                                            case 7:
                                                f.eq_s_b(1, 'u') && f.slice_del()
                                        }
                                })(),
                                (f.cursor = f.limit),
                                q() ||
                                    ((f.cursor = f.limit),
                                    (function () {
                                        var e, s
                                        if (
                                            f.cursor >= i &&
                                            ((s = f.limit_backward),
                                            (f.limit_backward = i),
                                            (f.ket = f.cursor),
                                            (e = f.find_among_b(m, 12)),
                                            (f.limit_backward = s),
                                            e)
                                        ) {
                                            if (((f.bra = f.cursor), 1 == e)) {
                                                if (!f.eq_s_b(1, 'u')) return !1
                                                f.slice_del()
                                            }
                                            return !0
                                        }
                                        return !1
                                    })() ||
                                        ((f.cursor = f.limit),
                                        (function () {
                                            var e, s, r, n
                                            if (
                                                f.cursor >= i &&
                                                ((s = f.limit_backward),
                                                (f.limit_backward = i),
                                                (f.ket = f.cursor),
                                                (e = f.find_among_b(l, 96)),
                                                (f.limit_backward = s),
                                                e)
                                            )
                                                switch (((f.bra = f.cursor), e)) {
                                                    case 1:
                                                        ;(r = f.limit - f.cursor),
                                                            f.eq_s_b(1, 'u')
                                                                ? ((n = f.limit - f.cursor),
                                                                  f.eq_s_b(1, 'g')
                                                                      ? (f.cursor = f.limit - n)
                                                                      : (f.cursor = f.limit - r))
                                                                : (f.cursor = f.limit - r),
                                                            (f.bra = f.cursor)
                                                    case 2:
                                                        f.slice_del()
                                                }
                                        })())),
                                (f.cursor = f.limit),
                                (function () {
                                    var e, s
                                    if (((f.ket = f.cursor), (e = f.find_among_b(d, 8))))
                                        switch (((f.bra = f.cursor), e)) {
                                            case 1:
                                                p() && f.slice_del()
                                                break
                                            case 2:
                                                p() &&
                                                    (f.slice_del(),
                                                    (f.ket = f.cursor),
                                                    f.eq_s_b(1, 'u') &&
                                                        ((f.bra = f.cursor),
                                                        (s = f.limit - f.cursor),
                                                        f.eq_s_b(1, 'g') &&
                                                            ((f.cursor = f.limit - s), p() && f.slice_del())))
                                        }
                                })(),
                                (f.cursor = f.limit_backward),
                                (function () {
                                    for (var e; ; ) {
                                        if (((f.bra = f.cursor), (e = f.find_among(a, 6))))
                                            switch (((f.ket = f.cursor), e)) {
                                                case 1:
                                                    f.slice_from('a')
                                                    continue
                                                case 2:
                                                    f.slice_from('e')
                                                    continue
                                                case 3:
                                                    f.slice_from('i')
                                                    continue
                                                case 4:
                                                    f.slice_from('o')
                                                    continue
                                                case 5:
                                                    f.slice_from('u')
                                                    continue
                                                case 6:
                                                    if (f.cursor >= f.limit) break
                                                    f.cursor++
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
                              return s.setCurrent(e), s.stem(), s.getCurrent()
                          })
                        : (s.setCurrent(e), s.stem(), s.getCurrent())
                })),
            e.Pipeline.registerFunction(e.es.stemmer, 'stemmer-es'),
            (e.es.stopWordFilter = e.generateStopWordFilter(
                'a al algo algunas algunos ante antes como con contra cual cuando de del desde donde durante e el ella ellas ellos en entre era erais eran eras eres es esa esas ese eso esos esta estaba estabais estaban estabas estad estada estadas estado estados estamos estando estar estaremos estará estarán estarás estaré estaréis estaría estaríais estaríamos estarían estarías estas este estemos esto estos estoy estuve estuviera estuvierais estuvieran estuvieras estuvieron estuviese estuvieseis estuviesen estuvieses estuvimos estuviste estuvisteis estuviéramos estuviésemos estuvo está estábamos estáis están estás esté estéis estén estés fue fuera fuerais fueran fueras fueron fuese fueseis fuesen fueses fui fuimos fuiste fuisteis fuéramos fuésemos ha habida habidas habido habidos habiendo habremos habrá habrán habrás habré habréis habría habríais habríamos habrían habrías habéis había habíais habíamos habían habías han has hasta hay haya hayamos hayan hayas hayáis he hemos hube hubiera hubierais hubieran hubieras hubieron hubiese hubieseis hubiesen hubieses hubimos hubiste hubisteis hubiéramos hubiésemos hubo la las le les lo los me mi mis mucho muchos muy más mí mía mías mío míos nada ni no nos nosotras nosotros nuestra nuestras nuestro nuestros o os otra otras otro otros para pero poco por porque que quien quienes qué se sea seamos sean seas seremos será serán serás seré seréis sería seríais seríamos serían serías seáis sido siendo sin sobre sois somos son soy su sus suya suyas suyo suyos sí también tanto te tendremos tendrá tendrán tendrás tendré tendréis tendría tendríais tendríamos tendrían tendrías tened tenemos tenga tengamos tengan tengas tengo tengáis tenida tenidas tenido tenidos teniendo tenéis tenía teníais teníamos tenían tenías ti tiene tienen tienes todo todos tu tus tuve tuviera tuvierais tuvieran tuvieras tuvieron tuviese tuvieseis tuviesen tuvieses tuvimos tuviste tuvisteis tuviéramos tuviésemos tuvo tuya tuyas tuyo tuyos tú un una uno unos vosotras vosotros vuestra vuestras vuestro vuestros y ya yo él éramos'.split(
                    ' '
                )
            )),
            e.Pipeline.registerFunction(e.es.stopWordFilter, 'stopWordFilter-es')
    }
})
