//shenghuo ling
// yuer

#include <weapon.h>
#include <skill.h>

inherit SWORD;

int do_study(string arj);


void create()
{
        set_name("ʥ����", ({ "shenghuo ling", "ling" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",
        "����һ����ڷ��������飬��������д������ֵ����֡�\n");
                set("material", "blacksteal");
                set("value", 5000);
               set("wield_msg",
"ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ������$n��\n");
                set("unequip_msg", "$N���ֽ�$n�������䡣\n");
        }
    init_sword(50);
        setup();
}
 void init()
{
	add_action("do_study","study");
}

int do_study(string arg)
{
        object me;

        me = this_player();

        if ( (int)me->query_skill("fanwen", 1) < 1)
	{
                write("�㲻�����ģ��޷��������Ķ�����\n");
		return 1;
	}
   if( (int)me->query("sen") > 30 )
 {

        me->add("sen", -30);

        message_vision("$N��ר���ж�ʥ�����ϵĹ���\n", me);

	if((int)me->query_skill("shenghuo-shengong",1)*(int)me->query_skill("shenghuo-
shengong",1)*(int)me->query_skill("shenghuo-shengong",1)/10 > me->query("combat_exp"))
	{
		write("Ҳ����ȱ��ʵս���飬���ʥ�����ϵ����������޷���ᡣ\n");
		return 1;
	}

        if ( (int)me->query_skill("shenghuo-shengong", 1) < 200)
        {
                me->improve_skill("shenghuo-shengong", (int)me->query_skill("fanwen", 1)/5+1);
                write("�����ʥ������ĥ��һ�ض����ƺ����е��ĵá�\n");
                me->set_temp("wall_learned",1);
        }
 }
    else
	{
             write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
             }

        if ( !me->query_temp("wall_learned") )
        {
                write("�����ʥ������ĥ��һ�ض��������������ص�̫��ǳ�ԣ�������˵�Ѻ���������
��\n");
        }
        return 1;
}



