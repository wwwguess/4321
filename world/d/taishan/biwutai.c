// Room: /d/taishan/biwutai.c
// Date: 98/2/24 

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIY "������̨" NOR);
	set("long", @LONG
    �������һƬ�տ��Ĺ㳡�����澭���˹��������ó���
��ʯ�̵��������룬�ϱ���������������������˰�������
��������������Ǳ�����̨�� 
    ÿ��������ɺ��ֶ����Ƽ��˴�����һ��һ�ȵı���
��ᣬ��ѡ��˭�ǵ��񡸺Ӻ����ơ�����ǿ�ߡ���̨���������
һ������(duizi)��
LONG
	);

	set("exits", ([
		"west" : __DIR__"riguan",
	]));
        set("objects", ([ 
        "/d/taishan/npc/referee":1,
]));
	set("item_desc",(["duizi": "��ߣ�"+HIR "���ķ����ܣ�һչ����\n" NOR+
       "�ұߣ�"+ HIR "�۰˷����ѣ��㵽Ϊֹ\n" NOR +
"������"+HIY " Ӣ �� �� �� \n" NOR]));
     set("no_kill",1);
     set("no_beg",1);
     set("no_sleep",1);
	
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

