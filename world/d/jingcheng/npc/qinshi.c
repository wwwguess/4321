// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

int ask_qin(object me);
void create()
{
	set_name("����", ({ "kee si" , "kee"  }));
	set("title","������ʦ");
	set("long",
	"һ�������ʵ�����ʦ������糾֮ɫ������б����һ���١�\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("force", 30);
	set("max_force", 30);
	set("force_factor", 5);
	set("combat_exp", random(4000));
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"��ʦ��ʱ�İѱ��ϵ��ٽ�������Ūһ�£�̾һ�������ְ��������ϡ�\n",	
        }) );
	set("inquiry",([
		"��"  : (: ask_qin :),
		"qin" : (: ask_qin :),
	]));
		
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/qin");
}

void init()
{
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 3, me);
                return;
        }
}

void greeting(object me)
{
	if( me->query_temp("qin") )
		me->delete_temp("qin");
}

int ask_qin(object me)
{
	object ob;
	ob = this_object();

	message_vision("$N����$n����˵������λ"+RANK_D->query_respect(me)+
	"Ī��Ҳ�Ƕ���֮�ˡ�\n", ob, this_player());
	message_vision("$N�ӱ��Ͻ��½�β�١�\n", ob);	
	message_vision("$N��̾һ���������������...... Ҳ�գ���������"+
	RANK_D->query_respect(me)+"����һ����\n", ob);
	this_player()->set_temp("qin", 1);   
	ob->set_skill("unarmed", 120);
	ob->set_skill("dodge", 120);
	ob->set_temp("apply/attack", 100);
	ob->set_temp("apply/defense", 200);
	ob->set_temp("apply/damage", 80);
	ob->set("combat_exp", 200000);
	return 1;
}                                     

int accept_object(object who, object what)
{
	object obj;
	
	if( !who->query_temp("qin") ) {
		message_vision("$N�����ĳ���$nһ�ۣ�ʲôҲû˵��", this_object(), who);
		return 1;
	}
	if( !(obj = present("jiaowei qin", this_object()))) {
		message_vision("$N������˼�Ķ�$n˵����������һ�����ҵ����Ѿ������ˡ�\n",
		this_object(), who);
		return 1;
	}
	if( what->query("money_id") && what->value() > 10000 ){
		tell_object(who,"��ʦ�������е��٣����˺��ģ�˵������λ"+
		RANK_D->query_respect(who)+"����\n"
		"����֮�ˣ���ز��ᱩ��������������������壬����������ɣ�\n");
		obj->move(who);
		return 1;
	}
}
