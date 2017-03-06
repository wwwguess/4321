// write by: dfbb 
// date 97/01/25

#ifndef __RANDOM_NAME_H__
#define __RANDOM_NAME_H__

string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��",
	"��","��","��" });
string *name_words = ({ "˳","��","��","��","��","��","��","��","־","��",
	"Т","��","��","��","��","��","��","ʢ","ʤ","��","��","��","ͬ","��",
	"��","��","��","¡","��","��","��","��","��","��","Ѫ" });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *nick_first_name = ({"׷��","����","�޳�","����","����","����",
        "�ɷ�","����","ԧ��","��ɱ","����","��ڤ","����","��Ѫ","׷��",
	"���","��ң","����һ","����һ","����һ","����","�޼�","����",
	"����","����","���һ","����һ","����һ","����"});
string *nick_wea_name =({"��","��","��","��","ǹ","�","��","��","��"});
string *all_color = ({HIR,HIY,HIG,HIB,HIM,HIW,HIC});

string get_rndname( );
string get_rndid( );
string get_rndnick();
 
string get_rndname( )
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];

	return name;

}

string get_rndid( )
{
	string id;
        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
	return id;
}

string get_rndnick( )
{
        string nickname;
        nickname = all_color[random(sizeof(all_color))]
                   +nick_first_name[random(sizeof(nick_first_name))];
        nickname +=all_color[random(sizeof(all_color))]+
                  nick_wea_name[random(sizeof(nick_wea_name))]+NOR;

        return nickname;  
 
}


#endif
