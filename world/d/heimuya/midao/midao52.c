//Room:/d/heimuya/midao/midao52.c 
//write by dfbb@hero
//Date: 1/25/96
inherit ROOM;

void create()
 {
        set("short", "�����ܵ�");
        set("long", @LONG ����������,ֻ��ǽ���ϵ���һյ�谵���͵�
 ��ʪ����ζ����ʮ�ֲ����,ֻ�����߳������ط�.
LONG );
        set("exits", ([
          "north" : __DIR__"midao43",
           "east" : __DIR__"midao53",
           "south" : __DIR__"midao63",
           "west" : __DIR__"midao51",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

