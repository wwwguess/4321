#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
 set("short", MAG "������" NOR);
        set("long", @LONG
 ���ǳ����ǵ��ϳ���,�����ϵ�����д���������֣��������š����ʼ�̵ĳ�ǽ
͸��һ�����ϡ���ǽ�����ż��Ÿ�ʾ��gaoshi).��Ϊ�Ǿ����������Թٱ���
�䱸ɭ�ϣ��������ͽ�ס�������ʡ������ǳ��
LONG
        );
        set("outdoors", "jingcheng");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

        set("exits", ([
        "north" : __DIR__"ndj3",
        ]));
        set("objects", ([
   "/obj/npc/wujiang1"+random(3) : 2,
// "open/diablo/dmenzg" : 1,
 "/obj/npc/bing" : 5,
        ]));
        setup();
}

string look_gaoshi()
{
  return FINGER_D->get_killer() + "\n\n\t\t�����ᶽ\n\n\t\t    �Ϲ���\n";
}
