#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIM"�ϴ��"NOR);
	set("long", @LONG
һ������ƽ����ʯ���֡�����Ϳ�������¥�����洫�����ʵ���
�����������Ƴ��Ĵ�ѧ�����Ӽࡣ·����һ�������ûʵĴ�Ժ�ӣ�
�������д����������ʹ�ڵı��ݡ��������ϴ�ֺ���ȸ��ֵ�
ʮ��·�ڡ�
LONG         
	);

	set("exits", ([
 "north" :__DIR__"ndj1",
 "south" :__DIR__"ndj3",
 "west"  :__DIR__"gbg",
 "east"  :__DIR__"gzj",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

