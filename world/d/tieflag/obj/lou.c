#include <ansi.h>
#include <weapon.h>
inherit CLAW;
void create()
{
        set_name( GRN "��ħ��" NOR, ({ "green claw", "claw" }) );
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "�����������ھš�\n");
                set("value", 350000);
                set("material", "sapphire");
		set("rigidity", 500000);
	        set("wield_msg", "$N����һ��$n��\n");
                set("unequip_msg", "$Nժ��$n\n");
                set("weapon_prop/agility", 5);
        }

        init_claw(95);
        setup();
}

void owner_is_killed(object killer)
{
	message_vision(HIR"\n \n ��ħ�� " NOR +"���ڵ��ϣ��ֵ���$N�Ļ��У�\n\n",killer);
	this_object()->move(killer);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	me->add("bellicosity",10+random(30));
        return HIG "$N������ӳ����ħ�������Ĺ����̹⣮����\n" NOR;
}

