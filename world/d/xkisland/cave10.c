// Room: /u/dunno/cave/cave10.c
// /u/dan/room/cave/cave10.c
// dan
inherit ROOM;

void create()
{
	set("short", "¶´¿ß");
	set("long", @LONG
Ç§Äê¹Å¶´,ËÄ´¦ÁôÏÂËêÔÂÄêºÛ.ËÄ±ÚÒÑ¾­°ß°ß²µ²µ,ÒÀÏ¡¿É¼ûÓĞ
Ğ©ÁÑºÛÁË.Ç½ÉÏÏóÊÇÓÃÓÍ²Ê»æ×ÅÒ»Ğ©×Ö»­.ËÄ±ÚÈ¼×Å¾ŞÖò,ÕÕÁÁÕû¸ö
¶´¿ß,ÊÒÄÚ¶«Ò»´¦,Î÷Ò»´¦¶¼ÊÇĞ©ÎäÁÖÈËÎï. Ç½±ÚÉÏµÄ×Ö¾­×ĞÏ¸±æÈÏ
ÊÇ£­­ £­ ÍÑ½£Ï¥Ç°ºá¡£
LONG
	); 
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cave9",
  "west" : __DIR__"cave11",
]));
	set("objects", ([ /* sizeof() == 2 */
    __DIR__"npc/npc4":1,  
    __DIR__"npc/npc5":1,
    ]));
	set("no_fight", 1); 
        set("no_sleep_room",1);
        setup();
}
  
void init()
{
	add_action("do_studywall", "studywall");
}

int do_studywall()
{
	object me;
        me = this_player();
	message_vision("$N×¨ĞÄµØÑĞ¾¿Ç½±ÚÉÏµÄÍ¼ĞÎ¡£\n", me); 
        if ((int)me->query_skill("literate", 1) >= 1)  
                  {
                       tell_object(me, "ÄãËÆºõ¿´²»¶®ÕâĞ©Í¼ĞÎ!\n");
                  }
        if ((int)me->query_skill("literate", 1) <= 0)
                 {
                       tell_object(me, "Äã·¢ÏÖÕâĞ©Í¼ĞÎËÆºõºÍÎä¹¦ÓĞ¹Ø!\n");
                  }
         if ((int)me->query_skill("sword", 1) <= 99
         && (int)me->query_skill("literate", 1) <= 0
               ) 
                {
                        tell_object(me, "ÕâĞ©¶ÔÓÚÄãÀ´ËµÌ«ÉîÁË£¡£¡£¡\n");
                 }
        if ((int)me->query_skill("sword", 1) >= 150
         && (int)me->query_skill("literate", 1) <= 0
               ) 
                {
                        tell_object(me, "ÕâĞ©¶ÔÓÚÄãÀ´ËµÌ«Ç³ÁË£¡£¡£¡\n");
                 }
        if ((int)me->query_skill("sword", 1) <= 149
         && (int)me->query_skill("sword", 1) >= 100 
         && (int)me->query_skill("literate", 1) <= 299 
               )       
        	{       
                        if( pow(to_float((int)me->query_skill("sword", 1)), 3.0) / 10.0 >to_float(me->query("combat_exp")) )
                        return notify_fail("Äã¾­Ñé²»×ã£¬¿ìÈ¥Á·¹¦.\n");
	        	me->receive_damage("gin", 20);
	        	me->improve_skill("sword", (me->query("int")));
		        tell_object(me, "ÄãµÄ»ù±¾½£·¨ÓĞËùÌá¸ß£¡£¡£¡\n");
	        }

	return 1;

}

