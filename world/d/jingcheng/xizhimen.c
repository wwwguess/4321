#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
 set("short", MAG "������" NOR);
        set("long", @LONG
 ���Ǿ��ǵĸ�����,�����ϵ�����д���������֣��������š����ʼ�̵ĳ�ǽ
͸��һ�����ϡ���ǽ�����ż��Ÿ�ʾ��gaoshi).��Ϊ�Ǿ����������Թٱ���
�䱸ɭ�ϣ��������ͽ�ס�������ʡ�������ͨ�����������,�����ǳ��
LONG
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

	set("exits", ([
 "east" :__DIR__"xchjie2",
	"west" : "/d/road/rcatolz0",
        ]));
        set("objects", ([
__DIR__"npc/xmenzg" : 1,
__DIR__"npc/bing" : 5,
        ]));
        setup();
}

string look_gaoshi()
{
  return FINGER_D->get_killer() + "\n\n\t\t�����ᶽ\n\n\t\t    �Ϲ���\n";
}
