#include <ansi.h>

inherit ROOM;

string look_gaoshi();

void create()
{
 set("short", MAG "������" NOR);
        set("long", @LONG
 ���Ǿ��ǵĸ�����,�����ϵ�����д���������֣��������š����ʼ�̵ĳ�ǽ
͸��һ�����ϡ���ǽ�����ż��Ÿ�ʾ��gaoshi).��Ϊ�Ǿ����������Թٱ���
�䱸ɭ�ϣ��������ͽ�ס�������ʡ�������ͨ�����������,�����ǳ���,�ϱ�
��һ����վ��
LONG
        );
        set("outdoors", "city");

        set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));

	set("exits", ([
        "east" : __DIR__"xchjie1",
	"west" :  __DIR__"dayidao10",
	"south":__DIR__"yizhan",
        ]));
        set("objects", ([
 "d/city/npc/wujiang1"+random(3) : 2,
 "open/diablo/xmenzg" : 1,
"/u/lysh/jiwei" : 1,
 "d/city/npc/bing" : 5,
        ]));
        setup();
}

string look_gaoshi()
{
  return FINGER_D->get_killer() + "\n\n\t\t�����ᶽ\n\n\t\t    �Ϲ���\n";
}
