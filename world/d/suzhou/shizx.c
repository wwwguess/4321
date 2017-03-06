//ROOM: d/suzhou/shizx.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"������"NOR);
	set("long", @LONG
	����������ݳǵ��������ˣ��������������˲�ͣ�ľ�������ߡ�һЩ����
���ӣ����ٶ�Դ��ż�ū���аԵ���Ҳ��һЩ����������������ա�����ʮ�����֣�
��֪����ʲô�¡��Ƚ϶��ԣ����߾�̫�����ˡ�����Ҳͦ���ֵģ��Ǳ�������������
���ɾ�¥���ϱߴ���һЩ�����Ц��������ʮ�ֺ��档
LONG
	);
	set("no_sleep_room",1);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"wroad1",
		"north" : __DIR__"nroad1",
		"south" : __DIR__"sroad1",
		"east" : __DIR__"eroad1",
]));
	set("objects", ([
		__DIR__"npc/hhgz" : 1,
		__DIR__"npc/myren" : 1,
		__DIR__"npc/girl" : 1,
]));
	setup();
}





