// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
#define JCH "/d/jingcheng/"

void create()
{
	set_name("��ף", ({ "miao zhu" , "keeper" }));
	set("title",YEL"��������"NOR);
	set("long",
	"һ������ͨͨ����ף�����ϲ������ƣ�һ˫������˪���֣�������һ�������۾������㡣\n");
	set("gender", "����");
	set("age", 65);
	set("attitude", "peaceful");
	set("combat_exp", 5000);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"��ף������̧��ͷ��������һ�ۡ�\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}

int accept_object(object who,object what)
{
	int value;

	if( what->query("money_id") && 
		( value = what->value() ) > 1000 )
	{
		tell_object(who,GRN"��ף�����Ц��һ�£�����Ŀ�����˵����"
		+RANK_D->query_respect(who)+"�������ƣ����춨�ᱣ����ġ�\n"NOR);
		if( who->query("shen") < 0 )
			who->add("shen", (int)(value/10));
		else
			who->add("shen", -(int)(value/20));
		if( !who->query("luck") )
			who->set("luck", 1);
		who->add("luck", 1);
	} else {
		message_vision("$N���ͷͷ����$n˵������лʩ�����ݣ������л�ˡ���\n",
		this_object(), who);
		remove_call_out("dest");
		call_out("dest", 1, what);
	}				
	return 1;
}
int accept_kill(object killer)
{
	int killer_max_qi;

	killer_max_qi = killer->query("max_kee");

	message_vision(YEL"��ף�����е���������������ˣ����ⱨӦ�ġ�\n"NOR, this_object());
	if( killer->query("luck") > 3 ){	
		killer->add("luck", -3);
		message_vision(YEL"��ף��֪����ǽ�Ϻδ�����һ�����أ����������顱��һ����$N\n"
		"�ͱ����˳�ȥ��\n"NOR, killer);
		tell_object(killer,YEL"�㿴��һ�������׵��콫һ�Ű�����߳�������.\n");
		killer->move(JCH"chhgch");	
	} else {
		message_vision(RED"��ף���صĶ���һ�½ţ������ѿ���һ���죬��ףһ�¾���ʧ\n"
		"�����ˡ�\n"NOR, killer);
		remove_call_out("dest");
		call_out("dest", 1, this_object());
		tell_object(killer,RED"�������Ĵ����������������������㷢�����������ֲ���,\n"
		"����������������û���ԡѪ��\n"NOR);
		killer->receive_wound("kee", (int)(killer_max_qi*9/10) );
		if( killer->query("kee") < 300 ){
			killer->die();
			return 1;
		}	
		killer->receive_damage("kee", -300 );
	}
	return 1;
}

void dest(object what)
{
	destruct(what);
}
