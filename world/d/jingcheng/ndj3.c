#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIM"ʮ��·��"NOR);
	set("long", @LONG
�������ϴ�ֺ���ȸ��ֵĽ���·�ڡ����ǳ����ģ�ԶԶ�Ŀ�
��������¥�����Ͽ��Ե����ǵ����š������߿��Ե�������֣�
��������Ե��׻���֡�
LONG         
	);

	set("exits", ([ 
 "west" :__DIR__"zhq1",
 "east" :__DIR__"zhq5",
 "north" :__DIR__"ndj2",
 "south" :__DIR__"ydmen",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

