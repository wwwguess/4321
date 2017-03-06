//NPC: /d/suzhou/npc/tianss.c
// by dwolf          
//97.11.6
           
#include <ansi.h>
inherit NPC;

string ask_for_yupei();

void create()
{
        set_name(RED"������"NOR, ({"miao ruolan", "miao", "ruolan"}));
        set("title", YEL"����Ů��"NOR);
        set("long",
                "���ǽ��ϴ������˷�ı���Ů������������ʲô�������˰졣\n"
        );

        set("gender", "Ů��");
        set("rank_info/respect", "��Ů");

        set("attitude", "peaceful");
        
        set("inquiry",([
                "����"  : (: ask_for_yupei :),
        ]));   
	set("count", 1);

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
	set("per", 30);
        set("max_kee", 300);
        set("max_gin", 100);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 10);
        set("combat_exp", 15000);
        set("score", 1000);
        set("apply/attack",  10);
        set("apply/defense", 10);

        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
       
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
                BLK"���������ĵ�˵�����������ڼ�һ���ܵ����ҡ���֪����˭�ܸ����Ӹ���Ϣ��������"NOR
        }) );

        add_money("silver", 50);
}

void init()
{
        add_action("do_decide", "decide");
}

string ask_for_yupei()
{
        object me;  

        me = this_player();
	
       if( !me->query("mark/����"))  
	{
	        if ((int)me->query("combat_exp") <= 200000 )
                	return RED"��·��ʮ��Σ�գ���ɲ�Ҫ���Լ�����������Ц��\n"NOR;        
       		if (query("count") < 1)
                	return "��Ǹ���������ˣ������Ѿ��������ˣ�лл��ĺ��⡣";

       		add("count", -1);

       		me->set_temp("pending/yupei", 1);
        		return "���壿��λ���ǵ��棿���������Ѷ�(decide)��������ҡ�\n";
        }  else {
		return "�㻹û��Ϊ���͵�����ô�����ˡ�";
	}
}

int do_decide()
{        
        object ob,me;
	me = this_player();

        if( !me->query_temp("pending/yupei") )
                return 0;

        message_vision(
                "$N���ͷ�����Ĵ�һ����\n\n"
                "$N�ӹ����壬��������غá�\n\n"
                "$N��������һ���֣�������ˡ�����\n\n",me);
	ob=new("/d/suzhou/npc/obj/yupei.c");
	ob->move(me);
        command("chat");
	command("admire");
        me->delete_temp("pending/yupei");
        me->add("combat_exp", 100);
	me->add("potential", 50); 
	me->set("mark/����", 1);
		return 1;
}

