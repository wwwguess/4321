#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", GRN"��������"NOR);
	set("long", @LONG
���������Ǿ��ǵĶ��š�һֱ�����߾Ϳ��Ե���ʹ��ˡ���������һ
Щִ�ڵı�ʿ��ʱ����������̫ƽ����һ�ɱ�������Ӣ�˲�������
��Ķ���������ʿ�����߳��Ǳ���ͨ�������Ĺٵ���
LONG
	);

	set("exits", ([
 "west" :__DIR__"dchjie4",
 "east" :__DIR__"dzhimen",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}

