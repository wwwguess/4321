//Room:/d/heimuya/midao/midao44.c 
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
          "north" : __DIR__"midao34",
           "east" : __DIR__"midao45",
           "west" : __DIR__"midao43",
         ]));
        setup();
        replace_program(ROOM); 
}
// the end of the file 

