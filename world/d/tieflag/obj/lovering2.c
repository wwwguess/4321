// tblade.c
#include <ansi.h> 
#include <armor.h> 



inherit FINGER;

void create()
{
        set_name( WHT "�׽����" NOR, ({ "lover ring","ring" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long","����һֻ��������İ׽���䡣\n
��������Ǵ���İ��飡\n"
);
                set("value", 100000000);
                set("material", "silver");
                set("rigidity", 1000000); 
        }
             set("wear_msg", "$N��$n����Ĵ�������,�����Ҹ���΢Ц��\n");
                set("unwield_msg", "$N����ذ�$n����ָ�ϳ���������\n");


        setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        me->add("bellicosity",10+random(30));
        return HIR "$N�����б�������������\n" NOR;
}
