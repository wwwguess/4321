#include <room.h>

inherit ROOM;

void create()
{
	set("short","ʯ��");
	set("long",@LONG
����һ��ʯ�ң�����͸��һ��˵�������������������������ʯ��
����ǽ�Ϲ���һ��ľ��������ͨ����������ǽ��д�������֣��߽���ϸ
���ϣ��ǣ����ҵ��ӣ�Ī����š�
LONG
);
	set("exits",([
	"enter" :__DIR__"cavehall",
	"south" :__DIR__"entrance",
	]) );
	create_door("south","��ʯ��","north",DOOR_CLOSED);
	setup();
}

int valid_leave(object me,string dir)
{
	if ( dir == "enter" && me->query("family/master_id") != "master outer" )
		return notify_fail("��ڱ�ħ����ס�ˣ�\n");
	return ::valid_leave(me,dir);
}

