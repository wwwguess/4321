// yinqiang.c 亮银枪

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name(HIW "亮银枪" NOR, ({ "liangyin qiang", "qiang" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄闪闪发光的亮银枪,上面缠着防止手滑的麻布\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回枪囊。\n");
        }
        init_spear(45);
        setup();
}
