// tblade.c
#include <ansi.h> 
#include <armor.h> 



inherit FINGER;

void create()
{
        set_name( WHT "白金钻戒" NOR, ({ "lover ring","ring" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long","这是一只闪闪发光的白金钻戒。\n
它代表的是纯真的爱情！\n"
);
                set("value", 100000000);
                set("material", "silver");
                set("rigidity", 1000000); 
        }
             set("wear_msg", "$N将$n轻轻的戴在手上,满脸幸福的微笑。\n");
                set("unwield_msg", "$N轻轻地把$n从手指上除了下来。\n");


        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        me->add("bellicosity",10+random(30));
        return HIR "$N的心中被爱意所充满。\n" NOR;
}
