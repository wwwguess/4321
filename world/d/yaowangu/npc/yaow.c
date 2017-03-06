// yaow.c 
//by dwolf
#include <ansi.h>
inherit NPC;

string ask_for_per();
string ask_for_con();

void create()
{
        set_name(RED"ҩ��"NOR, ({ "yao wang", "wang" }));
        set("title", GRN"ҩ������"NOR);
        set("gender", "����");
        set("long", "������ҽ���߳���ҩ��������ȥͦ�����ġ�\n");
        set("age", 75);

        set("int", 30);

        set("kee", 1500);
        set("max_kee", 1500);
        set("gin", 1000);
        set("max_gin", 1000);
//        set("shen_type", 5);

        set("combat_exp", 500000);
        set("attitude", "friendly");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);   
	set("inquiry", ([
		"����" : (: ask_for_per :),
		"����" : (: ask_for_con :),
	]));																																																								
     
	setup();
        add_money("gold", 1);
}           

string ask_for_per()
{     
	object me;
	me=this_player();
	if (me->query("per")>=26)
	{   if(me->query("gender")=="����")	 
	      return "���Ѿ���Ӣ���ˣ��������������ˡ�\n";
	   else
	     return "���Ѿ���Ư���ˣ������˰ɡ�\n";
		}					
	else
	{ 
	if( me->query_temp("mark/ҩ��") || me->query("combat_exp") <= 500000) return 0;
       	this_player()->add("combat_exp", -10000);
	this_player()->add("per", 5); 
	me->set_temp("mark/ҩ��", 1);
	me->set("mark/����", 1); 
	set("busy", 5);
	message_vision("ֻ��ҩ����Ϸ������ó�һ�׹��ߣ���$N
\n����һ��ʯ���ϣ���ʼ������\n", this_player()); 
	return YEL"�����ݣ���ѽ��--------����������\n"NOR;
	}
}
   
string ask_for_con()
{       
	object me;
	me=this_player();
        if (me->query("con")>=29)
              return "��ĸ��Ǻܺ���,�������������ˡ�\n";       
        if( me->query_temp("mark/ҩ��") ) return 0;
	this_player()->add("combat_exp", -15000);
	this_player()->add("con", 3); 
	set("busy", 5);
	me->set_temp("mark/ҩ��");
	me->set("mark/����");
	message_vision("ֻ��ҩ����Ϸ������ó�һ�׹��ߣ���$N
\n����һ��ʯ���ϣ���ʼ������\n", this_player()); 
	return YEL"�뽡������ѽ������������\n"NOR;
}

