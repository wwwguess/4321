#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
 set("short", MAG "������" NOR);
        set("long", @LONG
 ���ǳ����ǵĶ�����,�����ϵ�����д���������֣��������š����ʼ�̵ĳ�ǽ
͸��һ�����ϡ���ǽ�����ż��Ÿ�ʾ��gaoshi).��Ϊ�Ǿ����������Թٱ���
�䱸ɭ�ϣ��������ͽ�ס�������ʡ������ǳ��
LONG
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
        "west" : __DIR__"dchjie5",
	"east" : "/d/road/rtgtoca2",
        ]));
/*        set("objects", ([
set("objects", (
__DIR__"npc/xmenzg" : 1,
        ]));*/
        setup();
}

string look_gaoshi()
{
  return FINGER_D->get_killer() + "\n\n\t\t�����ᶽ\n\n\t\t    �Ϲ���\n";
}
