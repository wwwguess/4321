#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"��������"NOR);
	set("long", @LONG
������һ��������ʯ�����ϣ�����Ϳ쵽�������ˣ������Ƕ���
���ֺͰ׻���ֵ�ʮ��·�ڡ�·����һ�ҹ�ģ��С��լԺ��Ժ�ŵ�
������д�Ŷ���ġ���Զ�ھ֡���
LONG
	);

	set("exits", ([
 "west" :__DIR__"dchjie1",
 "east" :__DIR__"dchjie3",  
 "north" :__DIR__"biaoju1",
 "south" :__DIR__"yizhan",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

