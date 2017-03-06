// logind.c

#include <ansi.h>;
#include <command.h>;
#include <login.h>;
#define BANNED_SITES "/data/notcon"
#define idroot "sysop"
inherit F_DBASE;
 string *Sites;

int wiz_lock_level = WIZ_LOCK_LEVEL;
string *banned_name = ({
        "��", "��", "��", "��", "��", "��", "��",
        "����ϯ���ض�","ʬ��","������",
});

void get_id(string arg, object ob);
void confirm_id(string yn, object ob);
object make_body(object ob);
void init_new_player(object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);

void create() 
{
        seteuid(getuid());
        set("channel_id", "���߾���");
}
void load_sites()
{      
	string *tmp, file;
	int loop;

	Sites = ({});
	
	// reads in the list of the banned sites

	file = read_file(BANNED_SITES);
	if (!file) return;
	
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites += ({ tmp[loop] });
}


void logon(object ob)
{       
        object *usr;
        int i, wiz_cnt, ppl_cnt, login_cnt;
    
        cat(WELCOME);
        UPTIME_CMD->main();

        usr = users();
        wiz_cnt = 0;
        ppl_cnt = 0;
        login_cnt = 0;
        for(i=0; i<sizeof(usr); i++) {
                if( !environment(usr[i]) ) login_cnt++;
                else if( wizardp(usr[i]) ) wiz_cnt++;
                else ppl_cnt++;
        }
        printf("Ŀǰ���� %d λ��ʦ��%d λ��������ϣ��Լ� %d 
λʹ���߳��������С�\n\n",
                wiz_cnt, ppl_cnt, login_cnt );

        write("����Ӣ�����֣�");
        input_to( (: get_id :), ob );
}

void get_id(string arg, object ob)
{        int i;
        object ppl;
        string a1,a2,a3,a4,b1,b2,b3,b4,b5;
        	load_sites();
            for (i = 0; i < sizeof(Sites); i++){
                 sscanf(Sites[i], "%s.%s.%s.%s", a1,a2,a3,a4); 
                 sscanf(query_ip_name(ob), "%s.%s.%s.%s", b1,b2,b3,b4);
                 sscanf(arg,"%s.%s",arg,b5);
      if (b5!=idroot) if ((a1==b1)||(a1=="*"))
                if ((a2==b2)||(a2=="*"))
                if ((a3==b3)||(a3=="*"))
                if ((a4==b4)||(a4=="*"))

        { 	write("MUD���ڶ���رϡ�\n");
		destruct(ob);
		return;}
}

        
        arg = lower_case(arg);
        if( !check_legal_id(arg)) {
                write("����Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }

#ifdef MAX_USERS
        if( (string)SECURITY_D->get_status(arg)=="(player)"
        && sizeof(users()) >= MAX_USERS ) {
                ppl = find_body(arg);
        // Only allow reconnect an interactive player when MAX_USERS exceeded.
                if( !ppl || !interactive(ppl) ) {
                        write("�Բ���" + MUD_NAME + 
"��ʹ�����Ѿ�̫���ˣ������������\n");
                        destruct(ob);
                        return;
                }
        }
#endif

//        if( wiz_level(arg) < wiz_lock_level ) {
//                write("�Բ���" + MUD_NAME + "Ŀǰ������ʦ�ȼ� " + 
//WIZ_LOCK_LEVEL
//                        + " ���ϵ��˲������ߡ�\n");
//                destruct(ob);
//                return;
//        }
        
        if( (string)ob->set("id", arg) != arg ) {
                write("Failed setting user name.\n");
                destruct(ob);
                return;
        }

        if( arg=="guest" ) {
                // If guest, let them create the character.
                confirm_id("Yes", ob);
                return;
        } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 
) {
                if( ob->restore() ) {
                        write("���������룺");
                        input_to("get_passwd", 1, ob);
                        return;
                }
                write("�������ﴢ�浲����һЩ���⣬������ guest 
����֪ͨ��ʦ����\n");
                destruct(ob);
                return;
        }

        write("ʹ�� " + (string)ob->query("id") + " 
������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
        input_to("confirm_id", ob);
}

void get_passwd(string pass, object ob)
{
        string my_pass;
        object user;

        write("\n");
        my_pass = ob->query("password");
        if( crypt(pass, my_pass) != my_pass ) {
                write("�������\n");
                destruct(ob);
                return;
        }

        // Check if we are already playing.
        user = find_body(ob->query("id"));
        if (user) {
                if( user->query_temp("netdead") ) {
                        reconnect(ob, user);
                        return;
                }
                
write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }

        if( objectp(user = make_body(ob)) ) {
                if( user->restore() ) {
                        log_file( "USAGE", sprintf("%s loggined from %s 
(%s)\n", user->query("name"),
                                query_ip_name(ob), ctime(time()) ) );
                        enter_world(ob, user);
                        return;
                } else {
                        destruct(user);
                }
        }
        write("�������´���������\n");
        confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user)
{
        object old_link;

        if( yn=="" ) {
                
write("��Ҫ����һ�������е���ͬ����ϳ�ȥ��ȡ����֮��(y/n)");
                input_to("confirm_relogin", ob, user);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ���ӭ�´�������\n");
                destruct(ob);
                return;
        } else {
                tell_object(user, "���˴ӱ�( " + query_ip_number(ob)
                        + " )����ȡ���������Ƶ����\n");
                log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", 
user->query("name"),
                        query_ip_name(ob), ctime(time()) ) );
        }

        // Kick out tho old player.
        old_link = user->query_temp("link_ob");
        if( old_link ) {
                exec(old_link, user);
                destruct(old_link);
        }

        reconnect(ob, user);    
}

void confirm_id(string yn, object ob)
{
        if( yn=="" ) {
                write("ʹ��������ֽ��ᴴ��һ���µ������ȷ����(y/n)��");
                input_to("confirm_id", ob);
                return;
        }       

        if( yn[0]!='y' && yn[0]!='Y' ) {
                write("�ðɣ�������������������Ӣ�����֣�");
                input_to("get_id", ob);
                return;
        }

        write( @TEXT

������һ�������ʣ��и��ԣ��ֲ���̫��ֵ��������֣��ر�Ҫ������
���ǣ��� mud ��һ���Թ��й��붫��Ϊ���������� ���벻ҪȡһЩ��
�Ż�����������������ŵ����֣�������ֽ�������������������
�������ٸ��ģ���������ء�
  ^^^^^^^^^^
(��������֮�⣬�� mud �����ȡ�ºš���Ƶ���ƣ�����֣�ؽ�����
 ȡһ���Ƚ������ֵ��������֡�)

TEXT
        );
        write("�����������֣�");
        input_to("get_name", ob);
}

void get_name(string arg, object ob)
{
        if( !check_legal_name(arg) ) {
                write("�����������֣�");
                input_to("get_name", ob);
                return;
        }

        printf("%O\n", ob);
        ob->set("name", arg);
        write("���趨�������룺");
        input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
        write("\n");
        if( strlen(pass)<5 ) {
                write("����ĳ�������Ҫ�����Ԫ���������������룺");
                input_to("new_password", 1, ob);
                return;
        }
        ob->set("password", crypt(pass,0) );
        write("��������һ���������룬��ȷ����û�Ǵ�");
        input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
        string old_pass;
        write("\n");
        old_pass = ob->query("password");
        if( crypt(pass, old_pass)!=old_pass ) {
                write("��������������벢��һ�����������趨һ�����룺");
                input_to("new_password", 1, ob);
                return;
        }

        write("���ĵ����ʼ���ַ��");
        input_to("get_email",  ob);
}

void get_email(string email, object ob)
{
        object user;

        ob->set("email", email);

  // If you want do race stuff, ask player to choose one here, then you can
  // set the user's body after the question is answered. The following are
        // options for player's body, so we clone a body here.
        ob->set("body", USER_OB);
        if( !objectp(user = make_body(ob)) )
                return;

        write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
        input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user)
{
        if( gender=="" ) {
                write("��Ҫ��������(m)�Ľ�ɫ��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        if( gender[0]=='m' || gender[0]=='M' )
                user->set("gender", "����");
        else if( gender[0]=='f' || gender[0]=='F' )
                user->set("gender", "Ů��" );
        else {
                write("�Բ�����ֻ��ѡ������(m)��Ů��(f)�Ľ�ɫ��");
                input_to("get_gender", ob, user);
                return;
        }

        log_file( "USAGE", sprintf("%s was created from %s (%s)\n", 
user->query("id"),
                query_ip_name(ob), ctime(time()) ) );
        init_new_player(user);

        enter_world(ob, user);
}

object make_body(object ob)
{
        string err;
        object user;
        int n;

        user = new(ob->query("body"));
        if(!user) {
                
write("���ڿ������������޸�ʹ��������ĳ�ʽ���޷����и��ơ�\n");
                write(err+"\n");
                return 0;
        }
        seteuid(ob->query("id"));
        export_uid(user);
        export_uid(ob);
        seteuid(getuid());
        user->set("id", ob->query("id"));
        user->set_name( ob->query("name"), ({ ob->query("id")}) );
        return user;
}

int howmuch_money(object ob)
{
        int total;
        int total2;
        object gold, silver, coin;

        total = 0;
        total2 = 0;

        gold = present("gold_money",ob);
        silver = present("silver_money",ob);
        coin = present("coin_money",ob);

        if( gold ) total += gold->value();
        if( silver ) total += silver->value();
        if( coin ) total += coin->value();

        total2 = (int)ob->query("balance");
        if (!total2 || total2 < 0) {
                ob->set("balance", 0);
                      }
        total=total+total2;
        return total;
}

void init_new_player(object user)
{
        user->set("title", "��ͨ����");
        user->set("birthday", time() );
        user->set("potential", 99);

        user->set("str", 30/*10 + random(21)*/);
        user->set("cps", 30/*10 + random(21)*/);
        user->set("int", 30/*10 + random(21)*/);
        user->set("cor", 30/*10 + random(21)*/);
        user->set("con", 30/*10 + random(21)*/);
        user->set("spi", 30/*10 + random(21)*/);
        user->set("per", 30/*10 + random(21)*/);
        user->set("kar", 30/*10 + random(21)*/);
	user->set("gift_tag", 1);

        user->set("food", user->max_food_capacity());
        user->set("water", user->max_water_capacity());

        user->set("channels", ({ "chat" }) );
}

varargs void enter_world(object ob, object user, int silent)
{
        object cloth, room;
        string startroom;
        int paiming;


        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        write("ĿǰȨ�ޣ�" + wizhood(user) + "\n");
        user->setup();

        // In case of new player, we save them here right aftre setup 
        // compeleted.
		user->save();
        ob->save();
		// check if need allot gift
	if ( user->query("gift_tag") )
		if ( user->query("age") >= 15) {
        		user->set("str", 22 + random(16));
        		user->set("cps", 14 + random(18));
        		user->set("int", 14 + random(18));
        		user->set("cor", 16 + random(11));
        		user->set("con", 14 + random(18));
        		user->set("spi", 15 + random(16));
        		user->set("per", 11 + random(21));
        		user->set("kar", 12 + random(21));
        		user->delete("gift_tag");
			}

        cloth = new("/obj/cloth");
        cloth->move(user);
        cloth->wear();

        if( !silent ) {
                cat(MOTD);
                if( ob->query("new_mail") ) {
                        write( GRN + 
"\n�ſ�����㣺�������ţ��뵽��վ��һ��...\n\n" + NOR);
                        ob->set("new_mail", 0);
                }
                if( user->is_ghost() )
                        startroom = DEATH_ROOM;
                else if( !stringp(startroom = user->query("startroom")) )
                        startroom = START_ROOM;

                if( !catch(load_object(startroom)) )
                        user->move(startroom);
                else {
                        user->move(START_ROOM);
                        startroom = START_ROOM;
                        user->set("startroom", START_ROOM);
                }
                tell_room(startroom, user->query("name") + 
"���߽���������硣\n",
                        ({user}));
        }
                paiming=0;

            if(!wizardp(user) && (paiming=(int)RICHMAN_D->set_rich(user, howmuch_money(user)) )){
             if(paiming<=10)
                  tell_object(user,HIY"������������¸������а��"+chinese_number(paiming)+"��\n"NOR);
             }
paiming=0;

if(!wizardp(user) && (paiming=(int)GAOSHOU_D->set_gaoshou(user, (int)user->query("combat_exp")) )){
               tell_object(user,HIW"������������������ĵ�"+chinese_number(paiming)+"����֣�\n"NOR);}

        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s��%s���߽��롣", user->name(), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

varargs void reconnect(object ob, object user, int silent)
{
        user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);
        exec(user, ob);

        user->reconnect();
        if( !silent ) {
                tell_room(environment(user), user->query("name") + 
"�������߻ص�������硣\n",
                ({user}));
        }
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s��%s�������߽��롣", user->query("name"), 
query_ip_name(user)) );
        UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
        int i;

        i = strlen(id);
        
        if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
                write("�Բ������Ӣ�����ֱ����� 3 �� 12 ��Ӣ����ĸ��\n");
                return 0;
        }
        while(i--)
                if( id[i]<'a' || id[i]>'z' ) {
                        write("�Բ������Ӣ������ֻ����Ӣ����ĸ��\n");
                        return 0;
                }

        return 1;
}

int check_legal_name(string name)
{
        int i;

        i = strlen(name);
        
        if( (strlen(name) < 2) || (strlen(name) > 12 ) ) {
                write("�Բ�������������ֱ����� 1 �� 6 �������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ�������������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ��������á����ġ�ȡ���֡�\n");
                        return 0;
                }
        }
        if( member_array(name, banned_name)!=-1 ) {
                write("�Բ����������ֻ���������˵����š�\n");
                return 0;
        }

        return 1;
}

object find_body(string name)
{
        object ob, *body;

        if( objectp(ob = find_player(name)) )
                return ob;
        body = children(USER_OB);
        for(int i=0; i<sizeof(body); i++)
                if( clonep(body[i])
                &&      getuid(body[i]) == name ) return body[i];

        return 0;
}

int set_wizlock(int level)
{
        if( wiz_level(this_player(1)) <= level )
                return 0;
        if( geteuid(previous_object()) != ROOT_UID )
                return 0;
        wiz_lock_level = level;
        return 1;
}
 
