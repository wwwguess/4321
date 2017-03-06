#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void hungry();

int do_feed(string arg)
{
 object me;
 int max_food;
 if(arg!="baby") return 0; 
 me=this_player();
 if(!me->query("marks/����")) return 0;
 max_food = (query("str") - 10) * 10 + 200;
 if (query("food")<max_food) {
 message_vision(HIM"$N��С��ι������...\n"NOR,me);
 add("food",100);
 add("water",100);
 }
 else tell_object(me, HIM"�ĺ����Ѿ��Ա��ˡ�\n");
 return 1;
 
}

int do_drop(string arg)
{
 if (arg != "baby") return 0;
 say("�������ôС�ĺ��Ӷ�����? ̫�����ˡ�\n");
 return 1;
}

void create()
{
        set_name( "Ӥ��", ({ "baby" }) );
        if( !restore() ) {
		set("short", "Ӥ��(baby)");
                set("long","һ�����������е�Ӥ����");
                set("chat_chance",15);
                set("chat_msg", ({
                        (: hungry() :),
			"Ӥ���ֿ����ˣ�׼���򲼸û��ˡ��������������ˡ�\n",
                }) );
		set("chat_chance_combat", 15);
		set("chat_msg_combat", ({
"������˹���ߵĿ��ţ�������̵ļһ��ô�����µ�ȥ����!!!!\n"}));
                set("age", 0);
                set("str", 10);
                set("int", 30);
                set("cps", 30);
                set("kar", 30);
                set("cor", 30);
                set("spi", 30);
		set("mother", "none");
		set("father", "none");
        }
	set("nodrop", 1);
        setup();
}

void init()
{
 add_action("do_feed","feed");
 add_action("do_drop", "drop");
}

string query_save_file()
{
        return __DIR__"baby/"+(string)query("father")+"_"+(string)query("mother");
}

void reset()
{
        save();
}

void hungry()
{
	int max_food;
	max_food = ((int)query("str") - 10) * 10 + 200;
	if (query("food") < max_food) say("Ӥ����������������������Ƕ��ˡ�\n");
        if (query("water") < max_food) say("Ӥ����������������������ǿ��ˡ�\n");
}

int query_autoload() { return 1; }

