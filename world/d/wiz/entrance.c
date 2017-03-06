// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��ʦ�����");
	set("long",
		"��������ʦ���������ĵط����������ʲô���Ҫ����ʦ��֪����������\n"
	"����������;������������Ƕ�����Ϸ�е����⣬������ȷ�������ṩ��˵��\n"
	"�ļ���û��˵������������ʣ���ʦ����Ҫְ�𲢲��ǽ��������档\n");
	set("exits", ([
		"west" : "/d/wiz/hall1",
		"southeast": "/d/snow/inn" ]) );
	set("no_fight", 1);
	set("no_magic", 1);
        set("objects", ([
                "/d/wiz/npc/chpn" : 1 ]) );
	create_door("southeast", "ľ��", "northwest", DOOR_CLOSED);

	setup();
	call_other( "/obj/board/query_b", "???" );
}

int valid_leave(object me, string dir)
{
	if( dir=="west" && !wizardp(me) )
		return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
	return ::valid_leave(me, dir);
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
        invalid_cmds = ({"meditate", "practice", "study", "exercise", "learn", 
                         "respirate"
                       });
        i = member_array(cmd, invalid_cmds);
        if (i == -1) return 0;
        else write("��������ʦ�����, ����������������\�ĵط�Ŷ!\n");
        return 1;
}

