// kid2.c
// Made by Ysg(1997.10.22)

#include <ansi.h>
inherit NPC;

int ask_ren(object who);
int ask_ling(object who);

string *name =({
YEL"���������"NOR,YEL"��˽�����"NOR,YEL"ɳɮ����"NOR,YEL"��ɮ����"NOR,
});
string comm_name(){
	return name[ random( sizeof(name) ) ];
}   
string name = comm_name();

void create()
{
	set_name("С��",({ "kid" }) );
        set("gender", "����" );
        set("age", 7);
        set("long", 
	"���Ǹ����˼ҵ�С���ӣ�ͷ�����Ÿ�����С�裬����ȥ��ɰ���\n");
        set("combat_exp", 200);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");
	set("chat_chance", 10);
	set("chat_msg", ({
		"С���˷ܵ�������˵����������ඣ�����档\n",
		"С���������ˣ�������ˮ���������ˡ�\n",
	}));
	set("inquiry", ([
                "����"   : (: ask_ren :),
		"����"   : (: ask_ling :),
        ]));
        setup();
	carry_object(__DIR__"obj/cloth")->wear();
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
	if( me->query_temp("ling") ) me->delete_temp("ling");
	message_vision("С����������۹⿴��$N��\n", me);
}

int ask_ren(object who)
{
	message_vision("$N����ͷ�����룬������"+RANK_D->query_close(who)+
	"�����ñ�Ķ������㻻���ˣ���˵�ò��ã���\n", this_object());
	return 1;
}

int ask_ling(object who)
{
	if( who->query_temp("ling") ){
	tell_object(who,"С��ҡҡͷ��˵�����Ҳ�֪������ʲô�������ҴӼ���͵�����ġ�\n"
	"��˵�Ǻܹ��صĶ���Ӵ��\n");
	return 1;
	}
	return 0;
}

int accept_object(object who, object what)
{	
	object obj;

	if( strsrch( (string)what->query("name"), "����") != -1 ){
		if( (string)what->query("name") == name && !userp(what) ){
			tell_object(who,"С�����ĵĸ���һ�����ơ�\n");
			tell_object(who,GRN"С��������������˵����ɲ�Ҫ���߱���Ŷ��\n");
			who->set_temp("ling");
			obj = new(__DIR__"obj/lingpai");
			obj->move(who);
			return 1;
		} else {
		message_vision("$Nҡҡͷͷ˵���Ҳ�Ҫ�������Ҫ����"+name+"\n", this_object());
		return 1;
		}
	}
	tell_object(who,"С��һ�������˵����ӣ�˵���������ߣ����ߣ�����ƭС���ӡ���\n");
	command("shake "+who->query("id"));
	return 1;
}
