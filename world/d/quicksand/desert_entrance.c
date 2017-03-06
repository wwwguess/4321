#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "��Į��ɳ");
        set("long", @LONG
�����ڴ��ڿ������¯��ɳĮ�У��ȵ�����������͸������������������
�ķ�������ʲôҲ���������������۹����ķ�ɳ����ʲôҲ����������ؼ�
�·�ֻʣ����һ���ˡ�����»�����������ɳ�������ñ����ĸо���
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert0",
  "east"  : __DIR__"saiwai2",
]));
        set("item_desc", ([
  "sand" : "������������ɳ����һͷ���˶��ɵľ��ޣ�����������¡�\n",
  "��ɳ" : "������������ɳ����һͷ���˶��ɵľ��ޣ�����������¡�\n",
]));

        set("outdoors", "quicksand");

        setup();
}

void init()
{       object ob;
        string outexit;
        if( interactive( ob = this_player()))
        {
        if(query("exits/west")) delete("exits/west");
        outexit = __DIR__"desert"+(string) random(5)+ ".c";     
        set("exits/west", outexit);

        }
}

