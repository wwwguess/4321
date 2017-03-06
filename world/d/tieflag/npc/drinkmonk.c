
// drinkmonk.c
inherit NPC;
int go_in();
void create()
{
    set_name("酒肉和尚",({"drink monk","monk"}));
    set("long","这是一个僧不僧俗不俗，满头乱发的怪人\n");
    set("gender","男性");
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
          "肉"  : (: go_in :) ,
          "碧落赋" : "此赋本乃称颂苍穹碧落，但现有人用之形容武林中数大奇人\n",
           ])   );
    set("chat_chance",10);
    set("chat_msg",({
          "酒肉和尚喃喃吟道：“尔其动也，风雨如晦，雷电共作，尔其静也，体象皓镜�
强搪洌　盶n",
          "酒肉和尚掀开锅盖看了一眼\n",
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
    say ("酒肉和尚说道：“过来坐一坐吧”\n");
    return 1;
}
int go_in()
{
    command("say 你不说我倒忘了，待洒家把这碗肉送去再来说话。");
    message_vision("$N双手捧着肉碗，走到小门门口\n",this_object());
    command("cat");
    command("cat");
    message_vision("$N将门户轻轻推开一线，侧身走了进去。\n",this_object());
    this_player()->start_busy(2);
    call_out("disap",2);

    return 1;
}
void disap()
{
   message_vision("忽然屋内“啊呀”一声惊呼，“呛啷”一声碎响，显见那肉碗也落在�
厣蟎n",this_object());
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
