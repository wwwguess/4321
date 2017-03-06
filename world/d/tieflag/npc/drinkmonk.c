
// drinkmonk.c
inherit NPC;
int go_in();
void create()
{
    set_name("¾ÆÈâºÍÉĞ",({"drink monk","monk"}));
    set("long","ÕâÊÇÒ»¸öÉ®²»É®Ë×²»Ë×£¬ÂúÍ·ÂÒ·¢µÄ¹ÖÈË\n");
    set("gender","ÄĞĞÔ");
    set("no_arrest",1);
    set("age",42);
    set("int",20);
    set("cor",30);
    set("cps",20);
    set("gin",500);
    set("max_gin",500);
    set("eff_gin",500);
    set("max_kee",500);
    set("eff_kee",500);
    set("kee",500);
    set("max_sen",500);
    set("sen",500);
    set("eff_sen",500);
    set("combat_exp",1000000);
    set_skill("force",100);
    set_skill("lotusforce",100);
    set_skill("unarmed",100);
    set_skill("parry",50);
    set_skill("dodge",50);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",100);
    map_skill("force","lotusforce");
    set("attitude", "heroism");
    set("inquiry",([
          "meat": (: go_in :),
          "Èâ"  : (: go_in :) ,
          "±ÌÂä¸³" : "´Ë¸³±¾ÄË³ÆËÌ²Ôñ·±ÌÂä£¬µ«ÏÖÓĞÈËÓÃÖ®ĞÎÈİÎäÁÖÖĞÊı´óÆæÈË\n",
           ])   );
    set("chat_chance",10);
    set("chat_msg",({
          "¾ÆÈâºÍÉĞà«à«Ò÷µÀ£º¡°¶ûÆä¶¯Ò²£¬·çÓêÈç»Ş£¬À×µç¹²×÷£¬¶ûÆä¾²Ò²£¬ÌåÏóğ©¾µ£
¬ĞÇ¿ª±ÌÂä£¡¡±\n",
          "¾ÆÈâºÍÉĞÏÆ¿ª¹ø¸Ç¿´ÁËÒ»ÑÛ\n",
          }) );

    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{

    if( !me || environment(me) != environment() ) return 1;
    say ("¾ÆÈâºÍÉĞËµµÀ£º¡°¹ıÀ´×øÒ»×ø°É¡±\n");
    return 1;
}
int go_in()
{
    command("say Äã²»ËµÎÒµ¹ÍüÁË£¬´ıÈ÷¼Ò°ÑÕâÍëÈâËÍÈ¥ÔÙÀ´Ëµ»°¡£");
    message_vision("$NË«ÊÖÅõ×ÅÈâÍë£¬×ßµ½Ğ¡ÃÅÃÅ¿Ú\n",this_object());
    command("cat");
    command("cat");
    message_vision("$N½«ÃÅ»§ÇáÇáÍÆ¿ªÒ»Ïß£¬²àÉí×ßÁË½øÈ¥¡£\n",this_object());
    this_player()->start_busy(2);
    call_out("disap",2);

    return 1;
}
void disap()
{
   message_vision("ºöÈ»ÎİÄÚ¡°°¡Ñ½¡±Ò»Éù¾ªºô£¬¡°Çºà¥¡±Ò»ÉùËéÏì£¬ÏÔ¼ûÄÇÈâÍëÒ²ÂäÔÚµ
ØÉÏ\n",this_object());
   destruct( this_object());
}
void die()
{
    object sroom;
    object monk2;
    string myfile;
    myfile=base_name(this_object());
    //I do not want to specify an abs name of a room
    myfile=replace_string(myfile,"npc/drinkmonk","maoroom1");
    sroom =find_object(myfile);
    if(!objectp(sroom)) sroom=load_object(myfile);
    if( objectp(monk2 = present("drink monk", sroom)) && living(monk2))
               destruct(monk2);
    ::die();
}
