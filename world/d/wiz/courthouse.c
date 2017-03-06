// Room: /d/wiz/courthouse.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ƕ������µ���ʦ���ʻ����˵ķ�Ժ����һ���Ǳ��˼�ٻ���
��Ϊ̫������ˣ��Ż�������������𲻳����йٵ��������⣬��
�����ϼǺţ��������ε��˽��ᱻ���Լ��̣��úûش�ɡ�
LONG
	);
	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	set("objects", ([
		__DIR__"npc/judge":1 ]) );

	setup();
}

void init()
{
	add_action("re_route_cmd","",1);
}

int re_route_cmd(string str)
{
        string cmd;
        int i;
        string *invalid_cmds;
        cmd = query_verb();
	invalid_cmds = ({"enforce", "meditate", "practice", "study", "drop",
                         "exercise", "learn", "scribe", "conjure", "enchant",
                         "exert", "perform", "respirate"
                       });
        i = member_array(cmd, invalid_cmds);
        if (i == -1) return 0;
        else write("���˷�Ժ�㻹��ɶ��\��, �㲻���״��Ŷ��\n");
        return 1;
}

void test_me(object me)
{
	me->set_temp("old_startroom", me->query("startroom"));
	me->set("startroom", __FILE__);
	me->set_temp("last_location", base_name(environment(me)));
	message_vision("��Ȼһ��������ס��$N��\n", me);
	me->move(this_object());
}
