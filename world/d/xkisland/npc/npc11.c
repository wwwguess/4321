// xkx npc cave7 npc11.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("吕正平", ({"lv zhengping", "lv"}));
    set("nickname", "长白山畔快刀掌门人－－紫金刀");
    set("gender", "男性");
    set("age", 40);
    set("long", 
      "他一张西字脸，腮上一部虬髯。\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}
void init()
{
    ::init();
    call_out("greeting",1,this_player());
}

void greeting(object me)
{
    remove_call_out("greeting");
    tell_object(me,@LONG
这句若离开李白的原意，便不可解了。
LONG);
}





